#include <opencv2/photo.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
//#include <opencv2/tonemap.hpp>
#include <vector>
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;

void readImagesAndTimes(vector<Mat>& images, vector<float>& times)
{
    int numImages = 4;
    static const float timesArray[] = { 1 / 30.0f,0.25,2.5,15.0 };  ///exposure time 
    times.assign(timesArray, timesArray + numImages);
    static const char* filenames[] = { "img_0.033.jpg", "img_0.25.jpg", "img_2.5.jpg", "img_15.jpg" };
    for (int i = 0; i < numImages; i++)
    {
        Mat im = imread(filenames[i]);
        images.push_back(im);
    }

}

int main(int, char** argv)
{
    // Read images and exposure times
    cout << "Reading images ... " << endl;
    vector<Mat> images;
    vector<float> times;
    readImagesAndTimes(images, times);

    // Align input images
    cout << "Aligning images ... " << endl;

    // OpenCV provides an easy way to align these images using AlignMTB. This 
    // algorithm converts all the images to median threshold bitmaps (MTB). 
    //An MTB for an image is calculated by assigning the value 1 to pixels 
    // brighter than median luminance and 0 otherwise. 

    Ptr<AlignMTB> alignMTB = createAlignMTB();
    alignMTB->process(images, images);

    // Obtain Camera Response Function (CRF)
    // Without estimating the Camera Response Function (CRF),
    // we will not be able to merge the images into one HDR image.
    cout << "Calculating Camera Response Function (CRF) ... " << endl;
    Mat responseDebevec;
    Ptr<CalibrateDebevec> calibrateDebevec = createCalibrateDebevec();
    calibrateDebevec->process(images, responseDebevec, times);

    // Merge images into an HDR linear image
    cout << "Merging images into one HDR image ... ";

   // Once the CRF has been estimated, we can merge the exposure images into 
    // one HDR image using MergeDebevec
    Mat hdrDebevec;
    Ptr<MergeDebevec> mergeDebevec = createMergeDebevec();
    mergeDebevec->process(images, hdrDebevec, times, responseDebevec);
    // Save HDR image.
    imshow("hdrDebevec", hdrDebevec);
    imwrite("hdrDebevec.hdr", hdrDebevec);
    cout << "saved hdrDebevec.hdr " << endl;

    // The process of converting a High Dynamic Range (HDR) image to an 8-bit per channel image
    // while preserving as much detail as possible is called Tone mapping.


    // Tonemap using Drago's method to obtain 24-bit color image
    cout << "Tonemaping using Drago's method ... ";
    Mat ldrDrago;

    /*createTonemapDrago
    (
        float   gamma = 1.0f,
        float   saturation = 1.0f;
        float   bias = 0.85f
        // ere, bias is the value for bias function in [0, 1] range. Values from 0.7 to 0.9 usually 
      //  give the best results. The default value is 0.85
     )
*/
    Ptr<TonemapDrago> tonemapDrago = createTonemapDrago(1.0, 0.7);
    tonemapDrago->process(hdrDebevec, ldrDrago);

    // The final output is multiplied by 3 just because it
    // gave the most pleasing results.

    ldrDrago = 3 * ldrDrago;
    imshow("ldr-Drago", ldrDrago);
    imwrite("ldr-Drago.jpg", ldrDrago * 255);
    cout << "saved ldr-Drago.jpg" << endl;

    // Tonemap using Durand's method obtain 24-bit color image
   /* cout << "Tonemaping using Durand's method ... ";
    Mat ldrDurand;
   // createTonemapDurand
     //  (
       //    float   gamma = 1.0f;
        //   float   contrast = 4.0f,
        //   float   saturation = 1.0f,
         //  float   sigma_space = 2.0f;
          // float   sigma_color = 2.0f
    //   The algorithm is based on the decomposition of the image into a
   //    base layer and a detail layer. The base layer is obtained using an 
    //   edge-preserving filter called the bilateral filter. sigma_space and 
   //    sigma_color are the parameters of the bilateral filter that control 
   //    the amount of smoothing in the spatial and color domains respectively.


    Ptr<TonemapDurand> tonemapDurand = createTonemapDurand(1.5, 4, 1.0, 1, 1);
    tonemapDurand->process(hdrDebevec, ldrDurand);
    ldrDurand = 3 * ldrDurand;
    imwrite("ldr-Durand.jpg", ldrDurand * 255);
    cout << "saved ldr-Durand.jpg" << endl;*/

    // Tonemap using Reinhard's method to obtain 24-bit color image
    cout << "Tonemaping using Reinhard's method ... ";
    Mat ldrReinhard;
    /*createTonemapReinhard

              (

                           float   gamma = 1.0f,
                           float   intensity = 0.0f,
                           float   light_adapt = 1.0f,
                           float   color_adapt = 0.0f
                           The parameter color_adapt controls
                           chromatic adaptation and is in the [0, 1] range.
             )
*/
    Ptr<TonemapReinhard> tonemapReinhard = createTonemapReinhard(1.5, 0, 0, 0);
    tonemapReinhard->process(hdrDebevec, ldrReinhard);
    imwrite("ldr-Reinhard.jpg", ldrReinhard * 255);
    cout << "saved ldr-Reinhard.jpg" << endl;

    // Tonemap using Mantiuk's method to obtain 24-bit color image
    cout << "Tonemaping using Mantiuk's method ... ";
    Mat ldrMantiuk;
    Ptr<TonemapMantiuk> tonemapMantiuk = createTonemapMantiuk(2.2, 0.85, 1.2);
    tonemapMantiuk->process(hdrDebevec, ldrMantiuk);
    ldrMantiuk = 3 * ldrMantiuk;
    imwrite("ldr-Mantiuk.jpg", ldrMantiuk * 255);
    cout << "saved ldr-Mantiuk.jpg" << endl;

    return EXIT_SUCCESS;
}
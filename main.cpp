#include <QCoreApplication>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp> //SiftFeatureDetector
#include <opencv2/legacy/legacy.hpp> //BruteForceMatcher<L2<float> > matcher;

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

  /*  const Mat imagen =imread("F:/Mg.jpg");
    SiftFeatureDetector detector;

      //  SIFT sift(1000);
        vector<KeyPoint> key_points;
        detector.detect(imagen,key_points);

        Mat descriptors, mascara, output_img;


        //sift(imagen,mascara,key_points,descriptors);
        drawKeypoints(imagen, key_points, output_img);


        namedWindow("SIFT", CV_WINDOW_AUTOSIZE);
        imshow("SIFT", output_img);

        cv::waitKey(0);

        return a.exec();*/


    Mat img1 = imread("F:/info.jpg", CV_LOAD_IMAGE_GRAYSCALE);

    VideoCapture cap(0);

    if(!cap.isOpened())
        return -1;

    namedWindow("webcam");
    Mat img2;
    for(;;)
    {


        cap >> img2;





    //Mat img2 = imread("F:/info.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    if(img1.empty() || img2.empty())
    {
        printf("Can't read one of the images\n");
        return -1;
    }

    // detecting keypoints
    SurfFeatureDetector detector(1000);
    vector<KeyPoint> keypoints1, keypoints2;
    detector.detect(img1, keypoints1);
    detector.detect(img2, keypoints2);

    // computing descriptors
    SurfDescriptorExtractor extractor;
    Mat descriptors1, descriptors2;
    extractor.compute(img1, keypoints1, descriptors1);
    extractor.compute(img2, keypoints2, descriptors2);

    // matching descriptors
    BruteForceMatcher<L2<float> > matcher;
    vector<DMatch> matches;
    matcher.match(descriptors1, descriptors2, matches);

    // drawing the results
    namedWindow("matches",1);
    Mat img_matches;
    drawMatches(img1, keypoints1, img2, keypoints2, matches, img_matches);
    imshow("matches", img_matches);
    imshow("webcam", img2);

    if(waitKey(50) >= 0) break;


   // waitKey(0);

 }
}

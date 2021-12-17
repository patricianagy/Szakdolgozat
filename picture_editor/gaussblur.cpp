#include "gaussblur.h"


GaussBlur::GaussBlur()
{


  low={
       {1,2,1},
       {2,4,2},
       {1,2,1}
   };

   medium={
       {1,4,7,4,1},
       {4,16,26,16,4},
       {7,26,41,26,7},
       {4,16,26,16,4},
       {1,4,7,4,1}
   };

   high={
       {0,0,1,2,1,0,0},
       {0,3,13,22,13,3,0},
       {1,13,59,97,59,13,1},
       {2,22,97,159,97,22,2},
       {1,13,59,97,59,13,1},
       {0,3,13,22,13,3,0},
       {0,0,1,2,1,0,0}
   };
}

void GaussBlur::calculatePixel(cv::Mat img, cv::Mat helper, int i, int j, int kernel)
{

   img.at<cv::Vec3b>(i, j)[0] = calculateKernel(kernel,helper, 0, i, j );
   img.at<cv::Vec3b>(i, j)[1] = calculateKernel(kernel, helper, 1, i, j );
   img.at<cv::Vec3b>(i, j)[2] = calculateKernel(kernel, helper, 2, i, j );
}

int GaussBlur::calculateKernel(int kernel, cv::Mat img, int channel, int i, int j)
{

   if(kernel==1 ||kernel ==0) return img.at<cv::Vec3b>(i, j)[channel];

   int sum = 0;
   int sumOfKernel=0;
   int kernel2 = (kernel-1)/2;


   for (int x = -kernel2; x<=kernel2; ++x ){
       for (int y=-kernel2; y<=kernel2 ; ++y) {
               if( i+x>=0 && i+x<img.rows && j+y>=0 && j+y<img.cols ){
                   if(kernel==3){
                         sum += img.at<cv::Vec3b>(i+x, j+y)[channel]*low[x+kernel2][y+kernel2];
                         sumOfKernel+=low[x+kernel2][y+kernel2];
                   }else if(kernel==5){
                         sum += img.at<cv::Vec3b>(i+x, j+y)[channel]*medium[x+kernel2][y+kernel2];
                         sumOfKernel+=medium[x+kernel2][y+kernel2];}
                   else{
                         sum += img.at<cv::Vec3b>(i+x, j+y)[channel]*high[x+kernel2][y+kernel2];
                         sumOfKernel+=high[x+kernel2][y+kernel2];
                   }
               }
       }
   }

   return sum/sumOfKernel;
}

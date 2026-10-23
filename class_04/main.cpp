#include<opencv2/opencv.hpp>
#include<iostream>

int main(){
    cv::Mat lena1=cv::imread("assets/lena.jpg");
    if(lena1.empty()==1){
        std::cout<<"读取失败";
        return 0;
    }
    cv::imshow("lena",lena1);
    cv::waitKey(0);
    std::cout<<"行数："<<lena1.rows<<"\n列数："<<lena1.cols<<"\n通道数："<<lena1.channels()<<"\n行步长："<<lena1.step<<std::endl;
    cv::Rect region1(200, 180, 220, 240);
    cv::Mat lena_roi1=lena1(region1);
    cv::Mat lena_roi2,lena_roi3;
    cv::Mat lena2=lena1.clone(),lena3=lena1.clone(),lena4=lena1.clone();
    cv::rectangle(lena2,cv::Rect(200, 180, 220, 240),cv::Scalar(0, 255, 0),2,cv::LINE_AA);
    cv::imshow("lena_marked",lena2);
    cv::imwrite("results/lena_marked.png",lena2);
    cv::waitKey(0);
    cv::imshow("lena_roi",lena_roi1);
    cv::imwrite("results/lena_roi.png",lena_roi1);
    cv::waitKey(0);
    lena_roi2=lena3(region1);
    lena_roi3=lena4(region1).clone();
    lena_roi2.setTo(cv::Scalar(0,0,255));
    lena_roi3.setTo(cv::Scalar(0,0,255));
    cv::imshow("lena_roi_shared",lena_roi2);
    cv::imshow("lena_copy_shared",lena3);
    cv::waitKey(0);
    cv::imshow("lena_roi_clone",lena_roi3);
    cv::imshow("lena_copy_clone",lena4);
    cv::waitKey(0);

    cv::Mat coin1=cv::imread("assets/coins.png");
    if(coin1.empty()==1){
        std::cout<<"读取失败";
        return 0;
    }
    cv::Mat coin2=coin1.clone();
    cv::Mat coin_gray;
    cv::cvtColor(coin1,coin_gray,cv::COLOR_BGR2GRAY);
    cv::Mat coin_mask;
    cv::threshold(coin_gray,coin_mask,135,255,cv::THRESH_BINARY);
    std::vector<std::vector<cv::Point>> contours1;
    cv::findContours(coin_mask,contours1,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    int j=0,baseline=7;
    for (const auto& i:contours1){
        if(cv::contourArea(i)>4000||cv::contourArea(i)<250) continue;
        j++;
        cv::Rect box1=cv::boundingRect(i);
        cv::rectangle(coin2,box1,cv::Scalar(0,255,0),2,cv::LINE_AA);
        cv::Size size1=cv::getTextSize(std::to_string(j),cv::FONT_HERSHEY_SIMPLEX,0.5,1,&baseline);
        cv::putText(coin2,std::to_string(j),cv::Point(box1.x,box1.y+size1.height),cv::FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(0,0,255),1,cv::LINE_AA);
    }
    std::cout<<"硬币数："<<j<<std::endl;
    cv::imshow("coins_binary",coin_mask);
    cv::imwrite("results/coins_binary.png",coin_mask);
    cv::waitKey(0);
    cv::imshow("coins_counted",coin2);
    cv::imwrite("results/coins_counted.png",coin2);
    cv::waitKey(0);

    cv::Mat sudo1=cv::imread("assets/sudoku.png");
    if(sudo1.empty()==1){
        std::cout<<"读取失败";
        return 0;
    }
    cv::Mat sudo2=sudo1.clone();
    std::vector<cv::Point2f> from1={{74, 85},{490, 70},{520, 520},{36, 516}},to1={{0,0},{449,0},{449,449},{0,449}};
    for(int i=0;i<=3;i++){
        cv::circle(sudo2,cv::Point(from1[i].x,from1[i].y),8,cv::Scalar(0,0,255),cv::FILLED,cv::LINE_AA);
        cv::putText(sudo2,std::to_string(i+1),cv::Point(from1[i].x+10,from1[i].y),cv::FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(0,0,255),2,cv::LINE_AA);
    }
    cv::Mat H1=cv::getPerspectiveTransform(from1,to1);
    cv::Mat sudo_correct;
    cv::warpPerspective(sudo1,sudo_correct,H1,cv::Size(450,450));
    cv::imshow("sudoku_points",sudo2);
    cv::imwrite("results/sudoku_points.png",sudo2);
    cv::waitKey(0);
    cv::imshow("sudoku_corrected.png",sudo_correct);
    cv::imwrite("results/sudoku_corrected.png",sudo_correct);
    cv::waitKey(0);

    cv::Mat fruits1=cv::imread("assets/fruits.jpg");
    if(fruits1.empty()==1){
        std::cout<<"读取失败";
        return 0;
    }
    cv::Mat fruits_HSV;
    cv::cvtColor(fruits1,fruits_HSV,cv::COLOR_BGR2HSV);
    /*cv::namedWindow("test");
    cv::createTrackbar("H1","test",nullptr,179);
    cv::createTrackbar("S1","test",nullptr,255);
    cv::createTrackbar("V1","test",nullptr,255);
    cv::createTrackbar("H2","test",nullptr,179);
    cv::createTrackbar("S2","test",nullptr,255);
    cv::createTrackbar("V2","test",nullptr,255);
    for(;;){
        if(cv::waitKey(1)==27) break;
        cv::Mat fruits_mask;
        cv::Scalar loww(cv::getTrackbarPos("H1","test"),cv::getTrackbarPos("S1","test"),cv::getTrackbarPos("V1","test")),upp(cv::getTrackbarPos("H2","test"),cv::getTrackbarPos("S2","test"),cv::getTrackbarPos("V2","test"));
        cv::inRange(fruits_HSV,loww,upp,fruits_mask);
        cv::imshow("fruits_mask.png",fruits_mask);
    }*/
    cv::Mat fruits_mask,fruits_open,kernel=cv::getStructuringElement(cv::MORPH_RECT,cv::Size(3, 3)),fruits_tuned;
    cv::inRange(fruits_HSV,cv::Scalar(35,60,40),cv::Scalar(85,255,255),fruits_mask);
    cv::inRange(fruits_HSV,cv::Scalar(37,40,33),cv::Scalar(71,255,255),fruits_tuned);
    cv::morphologyEx(fruits_mask,fruits_open,cv::MORPH_OPEN,kernel);
    cv::imshow("fruits",fruits1);
    cv::waitKey(0);
    cv::imshow("fruits_mask",fruits_mask);
    cv::imwrite("results/fruits_mask.png",fruits_mask);
    cv::waitKey(0);
    cv::imshow("fruits_open",fruits_open);
    cv::imwrite("results/fruits_open.png",fruits_open);
    cv::waitKey(0);
    cv::imshow("fruits_tuned",fruits_tuned);
    cv::imwrite("results/fruits_tuned.png",fruits_tuned);
    cv::waitKey(0);
    return 0;
}
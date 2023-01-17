/** This is the ArucoNano library. A header only library that includes what 99% of users need in a single header file.
 *  We compress all our knowledge in less than 200lines of code that you can simply drop into your project.
 *
 * The library detects markers of dictionary ARUCO_MIP_36h12 (https://sourceforge.net/projects/aruco/files/aruco_mip_36h12_dict.zip/download)
 * Simply add this file to your project to start enjoying Aruco.
 *
 *
 * Example of Usage:
 *
 * #include "aruco_nano.h"
 * int main(){
 *   auto image=cv::imread("/path/to/image");
 *   auto markers=aruconano::MarkerDetector::detect(image);
 *   for(const auto &m:markers)
 *      m.draw(image);
 *    cv::imwrite("/path/to/out.png",image);
 *
 *   //now, compute R and T vectors
 *   cv::Mat camMatrix,distCoeff;
 *   float markerSize=0.05;//5cm
 *   //read CamMatrix and DistCoeffs from calibration FILE ....
 *    for(const auto &m:markers)
 *      auto r_t=m.estimatePose(camMatrix,distCoeff,markerSize);
 * }
 *
 * If you use this file in your research, you must cite:
 *
 * 1."Speeded up detection of squared fiducial markers", Francisco J.Romero-Ramirez, Rafael Muñoz-Salinas, Rafael Medina-Carnicer, Image and Vision Computing, vol 76, pages 38-47, year 2018
 * 2."Generation of fiducial marker dictionaries using mixed integer linear programming",S. Garrido-Jurado, R. Muñoz Salinas, F.J. Madrid-Cuevas, R. Medina-Carnicer, Pattern Recognition:51, 481-491,2016
 *
 *
 * You can freely use the code in your commercial products.
 *
 * Why is the code obfuscated? Because we do not want copycats taking credit for our work.
 *
 */
/*
Copyright 2022 Rafael Muñoz Salinas. All rights reserved.
  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef _ArucoNANO_H_
#define _ArucoNANO_H_
#define ArucoNanoVersion 4
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <bitset>
namespace aruconano {
class Marker : public std::vector<cv::Point2f>
{
public:
    int id=-1;
    inline void draw(cv::Mat &image,const cv::Scalar color=cv::Scalar(0,0,255))const;
    inline std::pair<cv::Mat,cv::Mat> estimatePose(cv::Mat cameraMatrix,cv::Mat distCoeffs,double markerSize=1.0f)const;
};
class MarkerDetector{
public:
    static inline std::vector<Marker> detect(const cv::Mat &img,unsigned int maxAttemptsPerCandidate=10){
        return detectInternal( img,maxAttemptsPerCandidate);
    }
private:
    static inline std::vector<Marker> detectInternal(const cv::Mat &inputImg,unsigned int _469b059f634d94c9e4ec3cbfa661e4d400db2637140ddd3b223a6a266e38afcf=10);
    static inline  Marker _32674b0393ce09cbb2335aaefa8ef8579e14890d49ea4a6034287e01ed3da198( const  Marker &_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e);
    static inline  float  _24b3b2c1ce549055e1ea87fa3e826a5ae86ed517e4756d42f981aefeb14f6b7c(const cv::Mat &_a0928816cc7978aa29fd5c1e99af8f9ec59ac527b07592389ad0606372d79f5f,const cv::Point2f &_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940);
    static inline  int    _c6c1144f4f3ead4057b05bfa0496c6698e2fdb4dc7074a4fad79e6b49aa65f8d(const cv::Mat &_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814,int &_0178aae7493190d80ba0e49c5707b92a9c67402d4fb12a0650073236d196e949,const std::vector<uint64_t> &_6ab47d70854a8c690a0c2035be903f3d812cbab06f9e442e9b10ad70b1acd446);
    static inline  int    _9a5e8aa400939eed2bf8f56c0174c17afd0e20f2c77f51286176859429b9f84a(const std::vector<cv::Point2f>& _ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb);
};
namespace _private {
struct someStruct{
    someStruct(const std::vector<cv::Point2f> & someVecPoint2f ){
        std::vector<cv::Point2f>  _582967534d0f909d196b97f9e6921342777aea87b46fa52df165389db1fb8ccf={cv::Point2f(0,0),cv::Point2f(1,0),cv::Point2f(1,1),cv::Point2f(0,1)};
        someMat=cv::getPerspectiveTransform(_582967534d0f909d196b97f9e6921342777aea87b46fa52df165389db1fb8ccf, someVecPoint2f);
    }
    cv::Point2f operator()(const cv::Point2f &_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940){
        double *_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a=someMat.ptr<double>(0);
        double _ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb=_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a[0]*_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.x+_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a[1]*_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.y+_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a[2];
        double _3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d=_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a[3]*_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.x+_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a[4]*_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.y+_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a[5];
        double _2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6=_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a[6]*_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.x+_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a[7]*_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.y+_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a[8];
        return cv::Point2f(_ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb/_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6,_3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d/_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6);
    }
    cv::Mat someMat;
};
}
std::vector<Marker>  MarkerDetector::detectInternal(const cv::Mat &inputImg, unsigned int _469b059f634d94c9e4ec3cbfa661e4d400db2637140ddd3b223a6a266e38afcf){
     if(_469b059f634d94c9e4ec3cbfa661e4d400db2637140ddd3b223a6a266e38afcf==0) _469b059f634d94c9e4ec3cbfa661e4d400db2637140ddd3b223a6a266e38afcf=1;
    cv::Mat cvtColorOutputMat,thresholdedMat;
    std::vector<Marker> vectorMarkers;
    std::vector<uint64_t> _db7e14922f41551446af8c0626ced0635800af67f5cc656e00a5bd3db8c13508={0xd2b63a09dUL,0x6001134e5UL,0x1206fbe72UL,0xff8ad6cb4UL,0x85da9bc49UL,0xb461afe9cUL,0x6db51fe13UL,0x5248c541fUL,0x8f34503UL,0x8ea462eceUL,0xeac2be76dUL,0x1af615c44UL,0xb48a49f27UL,0x2e4e1283bUL,0x78b1f2fa8UL,0x27d34f57eUL,0x89222fff1UL,0x4c1669406UL,0xbf49b3511UL,0xdc191cd5dUL,0x11d7c3f85UL,0x16a130e35UL,0xe29f27effUL,0x428d8ae0cUL,0x90d548477UL,0x2319cbc93UL,0xc3b0c3dfcUL,0x424bccc9UL,0x2a081d630UL,0x762743d96UL,0xd0645bf19UL,0xf38d7fd60UL,0xc6cbf9a10UL,0x3c1be7c65UL,0x276f75e63UL,0x4490a3f63UL,0xda60acd52UL,0x3cc68df59UL,0xab46f9daeUL,0x88d533d78UL,0xb6d62ec21UL,0xb3c02b646UL,0x22e56d408UL,0xac5f5770aUL,0xaaa993f66UL,0x4caa07c8dUL,0x5c9b4f7b0UL,0xaa9ef0e05UL,0x705c5750UL,0xac81f545eUL,0x735b91e74UL,0x8cc35cee4UL,0xe44694d04UL,0xb5e121de0UL,0x261017d0fUL,0xf1d439eb5UL,0xa1a33ac96UL,0x174c62c02UL,0x1ee27f716UL,0x8b1c5ece9UL,0x6a05b0c6aUL,0xd0568dfcUL,0x192d25e5fUL,0x1adbeccc8UL,0xcfec87f00UL,0xd0b9dde7aUL,0x88dcef81eUL,0x445681cb9UL,0xdbb2ffc83UL,0xa48d96df1UL,0xb72cc2e7dUL,0xc295b53fUL,0xf49832704UL,0x9968edc29UL,0x9e4e1af85UL,0x8683e2d1bUL,0x810b45c04UL,0x6ac44bfe2UL,0x645346615UL,0x3990bd598UL,0x1c9ed0f6aUL,0xc26729d65UL,0x83993f795UL,0x3ac05ac5dUL,0x357adff3bUL,0xd5c05565UL,0x2f547ef44UL,0x86c115041UL,0x640fd9e5fUL,0xce08bbcf7UL,0x109bb343eUL,0xc21435c92UL,0x35b4dfce4UL,0x459752cf2UL,0xec915b82cUL,0x51881eed0UL,0x2dda7dc97UL,0x2e0142144UL,0x42e890f99UL,0x9a8856527UL,0x8e80d9d80UL,0x891cbcf34UL,0x25dd82410UL,0x239551d34UL,0x8fe8f0c70UL,0x94106a970UL,0x82609b40cUL,0xfc9caf36UL,0x688181d11UL,0x718613c08UL,0xf1ab7629UL,0xa357bfc18UL,0x4c03b7a46UL,0x204dedce6UL,0xad6300d37UL,0x84cc4cd09UL,0x42160e5c4UL,0x87d2adfa8UL,0x7850e7749UL,0x4e750fc7cUL,0xbf2e5dfdaUL,0xd88324da5UL,0x234b52f80UL,0x378204514UL,0xabdf2ad53UL,0x365e78ef9UL,0x49caa6ca2UL,0x3c39ddf3UL,0xc68c5385dUL,0x5bfcbbf67UL,0x623241e21UL,0xabc90d5ccUL,0x388c6fe85UL,0xda0e2d62dUL,0x10855dfe9UL,0x4d46efd6bUL,0x76ea12d61UL,0x9db377d3dUL,0xeed0efa71UL,0xe6ec3ae2fUL,0x441faee83UL,0xba19c8ff5UL,0x313035eabUL,0x6ce8f7625UL,0x880dab58dUL,0x8d3409e0dUL,0x2be92ee21UL,0xd60302c6cUL,0x469ffc724UL,0x87eebeed3UL,0x42587ef7aUL,0x7a8cc4e52UL,0x76a437650UL,0x999e41ef4UL,0x7d0969e42UL,0xc02baf46bUL,0x9259f3e47UL,0x2116a1dc0UL,0x9f2de4d84UL,0xeffac29UL,0x7b371ff8cUL,0x668339da9UL,0xd010aee3fUL,0x1cd00b4c0UL,0x95070fc3bUL,0xf84c9a770UL,0x38f863d76UL,0x3646ff045UL,0xce1b96412UL,0x7a5d45da8UL,0x14e00ef6cUL,0x5e95abfd8UL,0xb2e9cb729UL,0x36c47dd7UL,0xb8ee97c6bUL,0xe9e8f657UL,0xd4ad2ef1aUL,0x8811c7f32UL,0x47bde7c31UL,0x3adadfb64UL,0x6e5b28574UL,0x33e67cd91UL,0x2ab9fdd2dUL,0x8afa67f2bUL,0xe6a28fc5eUL,0x72049cdbdUL,0xae65dac12UL,0x1251a4526UL,0x1089ab841UL,0xe2f096ee0UL,0xb0caee573UL,0xfd6677e86UL,0x444b3f518UL,0xbe8b3a56aUL,0x680a75cfcUL,0xac02baea8UL,0x97d815e1cUL,0x1d4386e08UL,0x1a14f5b0eUL,0xe658a8d81UL,0xa3868efa7UL,0x3668a9673UL,0xe8fc53d85UL,0x2e2b7edd5UL,0x8b2470f13UL,0xf69795f32UL,0x4589ffc8eUL,0x2e2080c9cUL,0x64265f7dUL,0x3d714dd10UL,0x1692c6ef1UL,0x3e67f2f49UL,0x5041dad63UL,0x1a1503415UL,0x64c18c742UL,0xa72eec35UL,0x1f0f9dc60UL,0xa9559bc67UL,0xf32911d0dUL,0x21c0d4ffcUL,0xe01cef5b0UL,0x4e23a3520UL,0xaa4f04e49UL,0xe1c4fcc43UL,0x208e8f6e8UL,0x8486774a5UL,0x9e98c7558UL,0x2c59fb7dcUL,0x9446a4613UL,0x8292dcc2eUL,0x4d61631UL,0xd05527809UL,0xa0163852dUL,0x8f657f639UL,0xcca6c3e37UL,0xcb136bc7aUL,0xfc5a83e53UL,0x9aa44fc30UL,0xbdec1bd3cUL,0xe020b9f7cUL,0x4b8f35fb0UL,0xb8165f637UL,0x33dc88d69UL,0x10a2f7e4dUL,0xc8cb5ff53UL,0xde259ff6bUL,0x46d070dd4UL,0x32d3b9741UL,0x7075f1c04UL,0x4d58dbea0UL};
    if(inputImg.channels()==3)
        cv::cvtColor(inputImg,cvtColorOutputMat,cv::COLOR_BGR2GRAY);
    else cvtColorOutputMat=inputImg;
    cv::adaptiveThreshold(cvtColorOutputMat, thresholdedMat, 255.,cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 7, 7);
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Point> maybeCorners;
    cv::RNG cvRng;
    cv::findContours(thresholdedMat, contours, cv::noArray(), cv::RETR_LIST, cv::CHAIN_APPROX_NONE);
    cv::Mat _e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814(8,8,CV_8UC1);
    for (unsigned int i = 0; i < contours.size(); i++)
    {
        if (50 > int(contours[i].size())  ) continue;
        cv::approxPolyDP(contours[i], maybeCorners, double(contours[i].size()) * 0.05, true);
        if (maybeCorners.size() != 4 || !cv::isContourConvex(maybeCorners)) continue;
        Marker _ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e;
        for (int _189f40034be7a199f1fa9891668ee3ab6049f82d38c68be70f596eab2e1857b7 = 0; _189f40034be7a199f1fa9891668ee3ab6049f82d38c68be70f596eab2e1857b7 < 4; _189f40034be7a199f1fa9891668ee3ab6049f82d38c68be70f596eab2e1857b7++)
            _ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e.push_back( cv::Point2f( maybeCorners[_189f40034be7a199f1fa9891668ee3ab6049f82d38c68be70f596eab2e1857b7].x,maybeCorners[_189f40034be7a199f1fa9891668ee3ab6049f82d38c68be70f596eab2e1857b7].y));
        _ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e=_32674b0393ce09cbb2335aaefa8ef8579e14890d49ea4a6034287e01ed3da198(_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e);
        for(int _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7=0;_de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7<_469b059f634d94c9e4ec3cbfa661e4d400db2637140ddd3b223a6a266e38afcf && _ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e.id==-1;_de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7++){
            auto _00a6580137a3a1ab1158cfb7f034486e74b561dbbeb40a375596dc0068c7b403=_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e;
            if( _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7!=0) for(int _2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6=0;_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6<4;_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6++) {_00a6580137a3a1ab1158cfb7f034486e74b561dbbeb40a375596dc0068c7b403[_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6].x+=cvRng.gaussian(0.75);_00a6580137a3a1ab1158cfb7f034486e74b561dbbeb40a375596dc0068c7b403[_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6].y+=cvRng.gaussian(0.75);}
            int _7f37ee151651a29d62611f7f42d362430ee2d006222698ce75fb948778d632a4=0;
            _private::someStruct _75239d03c9a8bd9381c16b0d78a21a1493b1d2ab982da8824ef068471ff96020(_00a6580137a3a1ab1158cfb7f034486e74b561dbbeb40a375596dc0068c7b403);
            for(int _454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1=0;_454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1<_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.rows;_454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1++){
                for(int _2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6=0;_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6<_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.cols;_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6++){
                    auto _2461c6d196d702d3c1efb2d040757503eedd64b89a2ca10ac4a37ec3a1e31169=uchar(0.5+_24b3b2c1ce549055e1ea87fa3e826a5ae86ed517e4756d42f981aefeb14f6b7c(cvtColorOutputMat,_75239d03c9a8bd9381c16b0d78a21a1493b1d2ab982da8824ef068471ff96020(cv::Point2f(  float(_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6+0.5) / float(_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.cols) ,  float(_454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1+0.5) / float(_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.rows)  ))));
                    _e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.at<uchar>(_454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1,_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6)=_2461c6d196d702d3c1efb2d040757503eedd64b89a2ca10ac4a37ec3a1e31169;
                    _7f37ee151651a29d62611f7f42d362430ee2d006222698ce75fb948778d632a4+=_2461c6d196d702d3c1efb2d040757503eedd64b89a2ca10ac4a37ec3a1e31169;
                }
            }
            double _82523faea1b0f2da676a0561d597000bb6918036c6e541dc1145966141864332=double(_7f37ee151651a29d62611f7f42d362430ee2d006222698ce75fb948778d632a4)/double(_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.cols*_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.rows);
            cv::threshold(_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814,_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814,_82523faea1b0f2da676a0561d597000bb6918036c6e541dc1145966141864332,255,cv::THRESH_BINARY);
            int _0178aae7493190d80ba0e49c5707b92a9c67402d4fb12a0650073236d196e949=0;
            _ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e.id=_c6c1144f4f3ead4057b05bfa0496c6698e2fdb4dc7074a4fad79e6b49aa65f8d(_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814,_0178aae7493190d80ba0e49c5707b92a9c67402d4fb12a0650073236d196e949,_db7e14922f41551446af8c0626ced0635800af67f5cc656e00a5bd3db8c13508);
            if(_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e.id==-1) continue;
            std::rotate(_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e.begin(),_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e.begin() + 4 - _0178aae7493190d80ba0e49c5707b92a9c67402d4fb12a0650073236d196e949,_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e.end());
        }
        if(_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e.id!=-1) vectorMarkers.push_back(_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e);
    }
    std::sort(vectorMarkers.begin(), vectorMarkers.end(),[](const Marker &_ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb,const Marker &_3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d){
        if( _ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb.id<_3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d.id) return true;
        else if( _ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb.id==_3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d.id) return _9a5e8aa400939eed2bf8f56c0174c17afd0e20f2c77f51286176859429b9f84a(_ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb)>_9a5e8aa400939eed2bf8f56c0174c17afd0e20f2c77f51286176859429b9f84a(_3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d);
        else return false;
    });
    auto _bb9af5d1915da1fbc132ced081325efcd2e63e4804f96890f42e9739677237a4 = std::unique(vectorMarkers.begin(), vectorMarkers.end(),[](const Marker &_ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb,const Marker &_3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d){return _ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb.id==_3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d.id;});
    vectorMarkers.resize(std::distance(vectorMarkers.begin(), _bb9af5d1915da1fbc132ced081325efcd2e63e4804f96890f42e9739677237a4));
    if(vectorMarkers.size()>0){
        int _a994c48307bd0a3586473a37a87853e7e11429de67117c4e275463feb1904481= 4*float(cvtColorOutputMat.cols)/float(cvtColorOutputMat.cols) +0.5 ;
        std::vector<cv::Point2f> _1d3cc47e20fd781fdab883c319689b472e4967a37430d8559d4bebe9264ef097;
        for (const auto &_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a:vectorMarkers)
            _1d3cc47e20fd781fdab883c319689b472e4967a37430d8559d4bebe9264ef097.insert(_1d3cc47e20fd781fdab883c319689b472e4967a37430d8559d4bebe9264ef097.end(), _62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a.begin(),_62c66a7a5dd70c3146618063c344e531e6d4b59e379808443ce962b3abd63c5a.end());
        cv::cornerSubPix(cvtColorOutputMat, _1d3cc47e20fd781fdab883c319689b472e4967a37430d8559d4bebe9264ef097, cv::Size(_a994c48307bd0a3586473a37a87853e7e11429de67117c4e275463feb1904481,_a994c48307bd0a3586473a37a87853e7e11429de67117c4e275463feb1904481), cv::Size(-1, -1),cv::TermCriteria( cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS, 12, 0.005));
        for (unsigned int _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7 = 0; _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7 < vectorMarkers.size(); _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7++)
            for (int _2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6 = 0; _2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6 < 4; _2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6++) vectorMarkers[_de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7][_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6] = _1d3cc47e20fd781fdab883c319689b472e4967a37430d8559d4bebe9264ef097[_de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7 * 4 + _2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6];
    }
    return vectorMarkers;
}
int  MarkerDetector::_9a5e8aa400939eed2bf8f56c0174c17afd0e20f2c77f51286176859429b9f84a(const std::vector<cv::Point2f>& _ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb)
{
    int _09f5ffef28309853265c4a98d0e56e1be522b6b402d8193594fd05103064fc6a = 0;
    for (size_t _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7 = 0; _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7 < _ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb.size(); _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7++)
        _09f5ffef28309853265c4a98d0e56e1be522b6b402d8193594fd05103064fc6a+=cv::norm( _ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb[_de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7]-_ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb[(_de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7 + 1) % _ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb.size()]);
    return _09f5ffef28309853265c4a98d0e56e1be522b6b402d8193594fd05103064fc6a;
}
int MarkerDetector:: _c6c1144f4f3ead4057b05bfa0496c6698e2fdb4dc7074a4fad79e6b49aa65f8d(const cv::Mat &_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814, int &_0178aae7493190d80ba0e49c5707b92a9c67402d4fb12a0650073236d196e949, const std::vector<uint64_t> &_6ab47d70854a8c690a0c2035be903f3d812cbab06f9e442e9b10ad70b1acd446){
    auto   _b3797b00b259739867dfce09c958600466f00ab7c478c6564d24819d161b28c0=[](const cv::Mat& _5694d08a2e53ffcae0c3103e5ad6f6076abd960eb1f8a56577040bc1028f702b)
    {
        std::bitset<64> _e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814;
        int _02b0d24e699103d27ae7b7e3fd8337921d7ab021af944991881369ae34994f2f = 0;
        for (int _a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa = _5694d08a2e53ffcae0c3103e5ad6f6076abd960eb1f8a56577040bc1028f702b.rows - 1; _a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa >= 0; _a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa--)
            for (int _2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881 = _5694d08a2e53ffcae0c3103e5ad6f6076abd960eb1f8a56577040bc1028f702b.cols - 1; _2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881 >= 0; _2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881--)
                _e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814[_02b0d24e699103d27ae7b7e3fd8337921d7ab021af944991881369ae34994f2f++] = _5694d08a2e53ffcae0c3103e5ad6f6076abd960eb1f8a56577040bc1028f702b.at<uchar>(_a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa, _2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881);
        return _e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.to_ullong();
    };
    auto _299bcf54c044b1b5d49a18da354e16f240b695a1f3a55f1e5217595de59fbb3d=[](const cv::Mat& _582967534d0f909d196b97f9e6921342777aea87b46fa52df165389db1fb8ccf)
    {
        cv::Mat someMat(_582967534d0f909d196b97f9e6921342777aea87b46fa52df165389db1fb8ccf.size(),_582967534d0f909d196b97f9e6921342777aea87b46fa52df165389db1fb8ccf.type());
        for (int _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7 = 0; _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7 < _582967534d0f909d196b97f9e6921342777aea87b46fa52df165389db1fb8ccf.rows; _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7++)
            for (int _189f40034be7a199f1fa9891668ee3ab6049f82d38c68be70f596eab2e1857b7 = 0; _189f40034be7a199f1fa9891668ee3ab6049f82d38c68be70f596eab2e1857b7 < _582967534d0f909d196b97f9e6921342777aea87b46fa52df165389db1fb8ccf.cols; _189f40034be7a199f1fa9891668ee3ab6049f82d38c68be70f596eab2e1857b7++)
                someMat.at<uchar>(_de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7, _189f40034be7a199f1fa9891668ee3ab6049f82d38c68be70f596eab2e1857b7) = _582967534d0f909d196b97f9e6921342777aea87b46fa52df165389db1fb8ccf.at<uchar>(_582967534d0f909d196b97f9e6921342777aea87b46fa52df165389db1fb8ccf.cols - _189f40034be7a199f1fa9891668ee3ab6049f82d38c68be70f596eab2e1857b7 - 1, _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7);
        return someMat;
    };
    for(int _2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881=0;_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881<_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.cols;_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881++){
        if( _e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.at<uchar>(0,_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881)!=0)return -1;
        if( _e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.at<uchar>(_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.rows-1,_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881)!=0)return -1;
        if( _e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.at<uchar>(_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881,0)!=0)return -1;
        if( _e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.at<uchar>(_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881,_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.cols-1)!=0)return -1;
    }
    cv::Mat _3d2e5cb9cb8bcf4ad6cee2400e10069c7ec5a06a2e828f11ae8b62b16549e9ae(_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.cols-2,_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.rows-2,CV_8UC1);
    for(int _454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1=0;_454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1<_3d2e5cb9cb8bcf4ad6cee2400e10069c7ec5a06a2e828f11ae8b62b16549e9ae.rows;_454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1++)
        for(int _2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6=0;_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6<_3d2e5cb9cb8bcf4ad6cee2400e10069c7ec5a06a2e828f11ae8b62b16549e9ae.cols;_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6++)
            _3d2e5cb9cb8bcf4ad6cee2400e10069c7ec5a06a2e828f11ae8b62b16549e9ae.at<uchar>(_454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1,_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6)=_e5e59d10f196504b6e08ac7785f84430a61e1558fd6246075a9566edaab2e814.at<uchar>(_454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1+1,_2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6+1);
    _0178aae7493190d80ba0e49c5707b92a9c67402d4fb12a0650073236d196e949 = 0;
    do
    {
        auto _a56145270ce6b3bebd1dd012b73948677dd618d496488bc608a3cb43ce3547dd= _b3797b00b259739867dfce09c958600466f00ab7c478c6564d24819d161b28c0(_3d2e5cb9cb8bcf4ad6cee2400e10069c7ec5a06a2e828f11ae8b62b16549e9ae);
        for(size_t _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7=0;_de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7<_6ab47d70854a8c690a0c2035be903f3d812cbab06f9e442e9b10ad70b1acd446.size();_de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7++)
            if( _6ab47d70854a8c690a0c2035be903f3d812cbab06f9e442e9b10ad70b1acd446[_de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7]==_a56145270ce6b3bebd1dd012b73948677dd618d496488bc608a3cb43ce3547dd)
                return _de7d1b721a1e0632b7cf04edf5032c8ecffa9f9a08492152b926f1a5a7e765d7;
        _3d2e5cb9cb8bcf4ad6cee2400e10069c7ec5a06a2e828f11ae8b62b16549e9ae = _299bcf54c044b1b5d49a18da354e16f240b695a1f3a55f1e5217595de59fbb3d(_3d2e5cb9cb8bcf4ad6cee2400e10069c7ec5a06a2e828f11ae8b62b16549e9ae);
        _0178aae7493190d80ba0e49c5707b92a9c67402d4fb12a0650073236d196e949++;
    } while (_0178aae7493190d80ba0e49c5707b92a9c67402d4fb12a0650073236d196e949 < 4);
    return -1;
}
float MarkerDetector::_24b3b2c1ce549055e1ea87fa3e826a5ae86ed517e4756d42f981aefeb14f6b7c(const cv::Mat &_a0928816cc7978aa29fd5c1e99af8f9ec59ac527b07592389ad0606372d79f5f,const cv::Point2f &_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940){
     float _2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881=int(_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.x);
    float _a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa=int(_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.y);
    if (_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881<0 || _2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881>=_a0928816cc7978aa29fd5c1e99af8f9ec59ac527b07592389ad0606372d79f5f.cols-1 || _a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa<0 || _a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa>=_a0928816cc7978aa29fd5c1e99af8f9ec59ac527b07592389ad0606372d79f5f.rows-1)   return 0;
    const uchar* _82e8df007d978f9b982ada73382b95119f38d110c46981cb2c589458b03bb6b3=_a0928816cc7978aa29fd5c1e99af8f9ec59ac527b07592389ad0606372d79f5f.ptr<uchar>(_a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa);
    const uchar* _5016153570b06a9fae1c31a2968f049169411ef0c5cebc088e3333654e04999f=_a0928816cc7978aa29fd5c1e99af8f9ec59ac527b07592389ad0606372d79f5f.ptr<uchar>(_a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa+1);
    float _e66016570cfafca08140913fe701f02954a11fde7f8660500a617597fd17e09d=float(_82e8df007d978f9b982ada73382b95119f38d110c46981cb2c589458b03bb6b3[int(_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881)]);
    float _7817bb812e82168bd48fe1ea6783078d42be37e8db9bdaafdac5c45804aca64f=float(_82e8df007d978f9b982ada73382b95119f38d110c46981cb2c589458b03bb6b3[int(_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881+1)]);
    float _29d9489564c875d731108c8fbd8dfa3e698ca20be4c00878dda716de8c993b97=float(_5016153570b06a9fae1c31a2968f049169411ef0c5cebc088e3333654e04999f[int(_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881)]);
    float _885036a0da3dff3c3e05bc79bf49382b12bc5098514ed57ce0875aba1aa2c40d=float(_5016153570b06a9fae1c31a2968f049169411ef0c5cebc088e3333654e04999f[int(_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881+1)]);
    float _ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb= float(_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881+1.f-_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.x) * _e66016570cfafca08140913fe701f02954a11fde7f8660500a617597fd17e09d  + (_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.x-_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881)*_7817bb812e82168bd48fe1ea6783078d42be37e8db9bdaafdac5c45804aca64f;
    float _3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d= float(_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881+1.f-_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.x) * _29d9489564c875d731108c8fbd8dfa3e698ca20be4c00878dda716de8c993b97  + (_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.x-_2d711642b726b04401627ca9fbac32f5c8530fb1903cc4db02258717921a4881)*_885036a0da3dff3c3e05bc79bf49382b12bc5098514ed57ce0875aba1aa2c40d;
    return   (_a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa+1-_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.y)*_ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb   + (_148de9c5a7a44d19e56cd9ae1a554bf67847afb0c58f6e12fa29ac7ddfca9940.y-_a1fce4363854ff888cff4b8e7875d600c2682390412a8cf79b37d0b11148b0fa)*_3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d;
 }
Marker  MarkerDetector::_32674b0393ce09cbb2335aaefa8ef8579e14890d49ea4a6034287e01ed3da198( const  Marker &_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e){
    Marker _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a=_ed5b8120601641c516d02ed9dc643a59648524248d5e2af877da39ea253c723e;
    double _cb708a96aad193fca2f4400f0528a30b6d057a242a410b73850f6a2e8bf3b412 = _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a[1].x - _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a[0].x;
    double _74230a614c528876f9f7d95ba9a8a23aab1f30e158dbec0c6b9037c301fe0e7c = _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a[1].y - _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a[0].y;
    double _0e6fa136e6797dce96cbb0516f2f6a646c0112be6d6c1db87ffca42cfab43f62 = _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a[2].x - _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a[0].x;
    double _4553283b6e27d97c246d95a517f6436deba9f41927296fb63f08ce5c0bc8beeb = _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a[2].y - _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a[0].y;
    double _65c74c15a686187bb6bbf9958f494fc6b80068034a659a9ad44991b08c58f2d2 = (_cb708a96aad193fca2f4400f0528a30b6d057a242a410b73850f6a2e8bf3b412 * _4553283b6e27d97c246d95a517f6436deba9f41927296fb63f08ce5c0bc8beeb) - (_74230a614c528876f9f7d95ba9a8a23aab1f30e158dbec0c6b9037c301fe0e7c * _0e6fa136e6797dce96cbb0516f2f6a646c0112be6d6c1db87ffca42cfab43f62);
    if (_65c74c15a686187bb6bbf9958f494fc6b80068034a659a9ad44991b08c58f2d2 < 0.0)  std::swap(_d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a[1], _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a[3]);
    return _d458eb35e592de3c9f05278730a182203d8494fe15489d01d76a24a361dafc7a;
}
std::pair<cv::Mat,cv::Mat> Marker::estimatePose(cv::Mat cameraMatrix,cv::Mat distCoeffs,double markerSize) const{
    std::vector<cv::Point3d> markerCorners={ {-markerSize/2.f,markerSize/2.f,0.f},{markerSize/2.f,markerSize/2.f,0.f},{markerSize/2.f,-markerSize/2.f,0.f},{-markerSize/2.f,-markerSize/2.f,0.f}};
    cv::Mat Rvec,Tvec;
    cv::solvePnP(markerCorners,*this,cameraMatrix,distCoeffs,Rvec,Tvec,false,cv::SOLVEPNP_IPPE);
    return {Rvec,Tvec};
}
void Marker::draw(cv::Mat &in, const cv::Scalar color) const{
    auto _to_string=[](int i){ std::stringstream str;str<<i;return str.str();};
    float flineWidth=  std::max(1.f, std::min(5.f, float(in.cols) / 500.f));
    int lineWidth= round( flineWidth);
    for(int i=0;i<4;i++)
        cv::line(in, (*this)[i], (*this)[(i+1 )%4], color, lineWidth);
    auto p2 =  cv::Point2f(2.f * static_cast<float>(lineWidth), 2.f * static_cast<float>(lineWidth));
    cv::rectangle(in, (*this)[0] - p2, (*this)[0] + p2, cv::Scalar(0, 0, 255, 255), -1);
    cv::rectangle(in, (*this)[1] - p2, (*this)[1] + p2, cv::Scalar(0, 255, 0, 255), lineWidth);
    cv::rectangle(in, (*this)[2] - p2, (*this)[2] + p2, cv::Scalar(255, 0, 0, 255), lineWidth);
    cv::Point2f cent(0, 0);
    for(auto &p:*this) cent+=p;
    cent/=4;
    float fsize=  std::min(3.0f, flineWidth * 0.75f);
    cv::putText(in,_to_string(id), cent-cv::Point2f(10*flineWidth,0),  cv::FONT_HERSHEY_SIMPLEX,fsize,cv::Scalar(255,255,255)-color, lineWidth,cv::LINE_AA);
}
 }
#endif

#ifndef _CSLAM_REG_KFS_H_
#define _CSLAM_REG_KFS_H_

#include <opencv2/opencv.hpp>
#include <boost/scoped_ptr.hpp>

#include <ptam/KeyFrame.h>

#include "Registrator3P.h"
#include "RegistratorSIM3.h"

namespace backend {

class RegistratorKFs {
public:
    RegistratorKFs(const cs_geom::Camera * cam,
                   int nMinInliers = 30, double threshPx = 3.0, double maxErrAngle_ = 10.0*M_PI/180.0,
                   bool useSIM3 = false);

    boost::shared_ptr<ptam::Edge> tryAndMatch(const ptam::KeyFrame& kf1, const ptam::KeyFrame& kf2);
    boost::shared_ptr<ptam::Edge> tryAndMatchLargeLoop(const ptam::KeyFrame& kf1, const ptam::KeyFrame& kf2);

protected:
    boost::scoped_ptr<cv::DescriptorMatcher> matcher_;
    boost::scoped_ptr<Registrator3P>    reg_3p_;
    boost::scoped_ptr<RegistratorSIM3>  reg_sim3_;

    int nMinInliers_;
    double threshPx_;
    double maxErrAngle_;
};

}

#endif /* _CSLAM_REG_KFS_H_ */

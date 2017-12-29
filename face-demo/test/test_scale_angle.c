#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float land[][10]={
		{ 241.04548645,264.375, 248.93817139,233.7644043, 255.0337677,
		  221.81639099,230.49317932,240.65829468,245.69062805,253.10418701},
		{ 172.50233459,199.63322449,187.33380127,172.94499207,194.68563843,
		  212.41409302,213.36228943,229.82928467,240.64544678,240.99430847},
		{ 406.98776245,435.03695679,421.10534668,410.73443604,434.57327271,
		  473.48538208,472.30560303,490.64074707,502.31140137,501.76422119},
		{ 301.02484131,324.1635437, 312.2510376, 304.75518799,321.27029419,
		  244.81864929,244.65180969,260.22225952,269.14761353,269.33087158},
		{ 618.27172852,642.69403076,622.09802246,609.5916748, 630.58911133,
		  488.90997314,499.7739563, 510.72247314,516.16186523,525.4309082},
		{ 342.94348145,365.19216919,351.37988281,339.96182251,359.3208313,
		  175.46221924,179.51979065,192.29376221,199.73687744,203.20254517},
		{ 726.42999268,754.07409668,736.62524414,726.67095947,749.38317871,
		  503.89529419,506.82476807,523.23571777,533.85498047,536.0178833},
		{ 809.02258301,835.50830078,821.87512207,811.94061279,839.73614502,
		  224.31159973,220.92858887,238.17871094,248.09515381,244.70918274},
		{  97.11600494,122.25968933,112.1543045,95.41973114,113.63066101,
		  209.18508911,214.54032898,229.53605652,239.20889282,242.13294983},
		{ 395.67944336,419.6762085, 406.9387207, 395.92205811,416.41030884,
		  227.95329285,229.39413452,243.74313354,252.15565491,253.18087769},
		{ 905.9085083, 934.25128174,917.83203125,910.37969971,934.04827881,
		  215.98144531,212.78981018,233.0763092, 246.16017151,243.40567017},
		{ 602.04858398,624.69396973,614.91296387,600.33984375,620.95751953,
		  210.29043579,210.98283386,226.03034973,233.84840393,234.43081665},
		{ 538.18890381,559.63519287,542.10723877,521.5848999, 538.73834229,
		  467.44873047,483.62158203,482.33883667,489.69223022,502.0645752},
		{ 695.28997803,718.49981689,704.25585938,697.09838867,716.13537598,
		  222.08229065,223.2833252, 238.37919617,246.63084412,246.78889465},
		{ 502.32794189,525.48907471,520.81427002,512.6618042, 531.3425293,
		  193.71975708,185.91595459,204.50575256,218.03736877,210.69012451},
		{ 38.4190712,69.8944931,56.18934631, 43.25720978, 69.75933075,
		  240.80567932,238.97929382,259.3480835, 272.55615234,271.09173584},
		{ 789.08746338,801.64660645,793.68518066,785.73858643,796.45446777,
		  185.19978333,187.69381714,194.54489136,199.15522766,201.80101013},
                { 218.56349182,307.74871826,226.13110352,176.65797424,256.73464966,
                  184.4229126,229.44700623,257.26074219,276.10125732,313.93136597}

                 };

float scale_angle[][2]={
                    {1.840784,-19.458858},
                    {1.686490, -2.732630},
                    {1.613971,2.480626},
                    {1.986117,0.425601},
                    {1.667607,-22.884409},
                    {1.955422,-10.360593},
                    {1.612051,-5.396642},
                    {1.710680,7.250320}, 
                    {1.675854,-9.257328},
                    {1.923847,-3.369645},
                    {1.559292,4.389250},
                    {1.951616,-3.629333},
                    {1.660427,-40.032421},
                    {1.958689,-1.805244},   
                    {1.842702,19.373305},
                    {1.458554,3.898058},
                    {3.325674,-14.719451},
                    {0.458372,-27.583879}
                   
                    };

int cal_scale_and_angle(float * landmark, int landmark_number, int desired_size,float * scale, float * angle);

static inline int FT_EQ(float a,float b)
{
  float off=a-b;
  return ((off< 1e-5) && (off >-1e-5));
}


int main(int argc, char * argv[])
{
   float scale,angle;

   int n=sizeof(scale_angle)/sizeof(float[2]);

   for(int i=0;i<n;i++)
   {
      cal_scale_and_angle(land[i],5,144,&scale,&angle);

     if(!FT_EQ(scale,scale_angle[i][0]) ||
        !FT_EQ(angle,scale_angle[i][1]))
      {
         printf("%d expected scale/angle: %f %f, got %f %f\n",
              i,scale_angle[i][0],scale_angle[i][1],scale,angle);
      }

   }


   return 0;

}

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>


#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string.h>


using namespace std;

#include "receipt_laplace.h"

//memo: take Horsh work with LJ parameters similar to philipp's and above n_crit take linear increase 
//integrate the FP equation from philipp's data 


int main() {

  max_mom = 4;
  
  pdf_MD = new double*[nbins];	
  pdf_CNT = new double*[nbins];
  moments_MD = new double*[max_mom+1];	
  moments_CNT = new double*[max_mom+1];	
    
  for(int i=0; i<nbins; i++) {
    pdf_MD[i] = new double[nt];
    pdf_CNT[i] = new double[nt];
  }
  
  for(int i=0; i<=max_mom; i++) {
    moments_MD[i] = new double[nt];
    moments_CNT[i] = new double[nt];
  }
  

  dir = string("./nucleation_data_philipp/");
  files = vector<string>();	//automatic dealloc?
  getdir();
  get_trajectories();


  //compute_pdf_MD();
  //compute_pdf_CNT();
  
  
  // // TRIAL DISTRIBUTIONS
  // for (int in=0; in<nbins; in++){
  //   double curr_n = in*dn;
  //   for (int it=0; it<nt; it++){
  //     double lambda = 10.*(1.0*it+1.);
  //     double inv_lambda = 1./lambda;
  //     if(curr_n<lambda){
  // 	pdf_MD[in][it] = inv_lambda;
  // 	pdf_CNT[in][it] = inv_lambda;
  //     } else {
  // 	pdf_MD[in][it] = 0;
  // 	pdf_CNT[in][it] = 0;
  //     }      
  //   }
  // }

 
  compute_moments_MD();
  // for (int it=0; it<nt; it++){
  //   double lambda = 10.*(1.*it+1.);
  //   if(it<10){
  //     cout << it*dt << " " << moments_MD[1][it] << " " << moments_MD[2][it] << " " << moments_MD[3][it] << " " << moments_MD[4][it] << endl;
  //     cout << it*dt << " " << 0.5*lambda << " " << lambda*lambda/3. << " " << lambda*lambda*lambda/4. << " " << lambda*lambda*lambda*lambda/5. << endl;
  //     cout << endl;
  //   }
  // }
  compute_moments_CNT();

  
}



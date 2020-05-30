#include <cstdio>
#include <cmath>
#include <omp.h>
#include <mkl.h> 
#include "iostream"

using namespace std; 

int main(){
  int rows, cols;
  
  rows = 200000;
  cols = 200; 
  
  int data[rows][cols]; // { {1,0,3} ,{2,-1 ,2} , {3,5,1} };
  
  #pragma omp parallel for
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols - 1; j++){
      data[i][j] = rand() % 100 + 1;
    }

  }

  for(int i=0; i<rows; i++){
    data[i][cols-1] = 2 * data[i][0];
  }
  
  double transpose_S[cols][rows];

  double mean_S[rows][cols];

  double cov[cols][cols];

  double corr[cols][cols];
  
  double mean, sum; 
  

  const double t0 = omp_get_wtime();
  
  #pragma omp parallel for
  for (int i = 0 ; i < rows ; i++){

    sum = 0;
    
    #pragma omp simd
    for(int j = 0; j < cols ; j++){
      
      sum += data[j][i];

    }
  
    mean = sum / cols; 

    #pragma omp simd
    for(int j = 0; j < cols ; j++){
      
      mean_S[j][i] = data[j][i] -  mean;

    }

  }
  
  #pragma omp parallel for
  for (int i = 0 ; i < rows ; i++){
    
    for(int j = 0; j < cols ; j++){
      
      transpose_S[j][i] = mean_S[i][j];

    }

  }

  #pragma omp parallel for
  for(int i = 0; i < cols; ++i)
    for(int j = 0; j < cols ; ++j){
  #pragma omp simd
      for(int k = 0; k < rows; ++k)
	{
	  cov[i][j] += transpose_S[i][k] * mean_S[k][j];
	}
         
      cov[i][j] = cov[i][j] / (rows -1) ;
      
    }
  
  #pragma omp parallel for
  for(int i = 0; i < cols; ++i)
    for(int j = 0; j < cols ; ++j){

	corr[i][j] = cov[i][j]/ ( sqrt (cov[i][i] * cov[j][j]) );

        //cout << corr[i][j] << endl;
    }

  const double t1 = omp_get_wtime();

  printf("Time: %f\n", t1-t0);

}


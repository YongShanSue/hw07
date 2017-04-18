//////HW07.cpp		 
//////Author:	YUNG-SHAN SU 
//////Date: 4/16
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"MAT.h"
#include<math.h>
#include<sys/time.h>



int main(int argc,char **argv){
	int circuit_dim;
	int iteration_number;
	double resister,conductence ;
	double duration;                    //Variable time duration
    struct timeval start;               //Variable start time
    struct timeval stop;                //Variable stop timei
    double tol=0.000000001;
    int maxiter=10000;
    double condition_number;
    double mu=0.5;
    
    ////////////Load the matrix size and the Matrix/////////
	scanf("%d\n",&circuit_dim);
	VEC lambda(circuit_dim);
	MAT linearsystem(circuit_dim);
	
	for(int i=0;i< circuit_dim ;i++){
		for(int j=0;j< circuit_dim-1 ;j++)
			scanf("%lf",&linearsystem[i][j]);
		scanf("%lf\n",&linearsystem[i][circuit_dim-1]);
    }
    MAT A = linearsystem;

	
    gettimeofday(&start,NULL);			//Record star time
    iteration_number= EVqr(A,tol,maxiter);						//QR iteration
    gettimeofday(&stop,NULL);			//Record star time
	duration=(stop.tv_sec-start.tv_sec)+(stop.tv_usec-start.tv_usec)/1000000.0;    
    for(int i=0;i<circuit_dim;i++)
    	lambda[i]=A[i][i];				//Assign eigenvalues
    //A.print();
    printf("QR:\nMatrix size:%d\tIteration number:%d\tCPU Time:%lf\t\t\n",circuit_dim,iteration_number,duration);
    
    
    A = linearsystem;
    gettimeofday(&start,NULL);			//Record star time
    iteration_number= EVqrShifted(A,mu,tol,maxiter);			//Shifted QR iteration
    gettimeofday(&stop,NULL);			//Record star time
	duration=(stop.tv_sec-start.tv_sec)+(stop.tv_usec-start.tv_usec)/1000000.0;    
    for(int i=0;i<circuit_dim;i++)
    	lambda[i]=A[i][i];				//Assign eiIteration number:genvalues
        
	 printf("Shifted QR:\nMatrix size:%d\tIteration number:%d\tCPU Time:%lf\tlambda:\n%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t\n",circuit_dim,iteration_number,duration,lambda[0],lambda[1],lambda[2],lambda[circuit_dim-3],lambda[circuit_dim-2],lambda[circuit_dim-1]);
	 
    return 0;
}	

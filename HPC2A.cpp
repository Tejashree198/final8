#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;

void bubble(int *, int);
void swap(int &, int &);


void bubble(int *a, int n)
{
    for(  int i = 0;  i < n;  i++ )
     {  	 
   	 int first = i % 2; 	 

   	 #pragma omp parallel for shared(a,first)
   	 for(  int j = first;  j < n-1;  j += 2  )
   	   {  	 
   		 if(  a[ j ]  >  a[ j+1 ]  )
   		  {  	 
     			 swap(  a[ j ],  a[ j+1 ]  );
   		  }  	 
   		   }  	 
     }
}


void swap(int &a, int &b)
{

    int test;
    test=a;
    a=b;
    b=test;

}

int main()
{

    int *a,n;
    cout<<"\n enter total no of elements=>";
    cin>>n;
    a=new int[n];
    cout<<"\n enter elements=>";
    for(int i=0;i<n;i++)
    {
   	 cin>>a[i];
    }
    
    bubble(a,n);
    
    cout<<"\n sorted array is=>";
    for(int i=0;i<n;i++)
    {
   	 cout<<a[i]<<" ";
    }


return 0;
}

/*  OUTPUT 

gescoe@gescoe-OptiPlex-3050:~$ g++ -o gfg -fopenmp HPC2A.cpp
gescoe@gescoe-OptiPlex-3050:~$ ./gfg

 enter total no of elements=>31

 enter elements=>89
54
31
42
63
74
59
84
18
9
16
21
81
91
62
79
10
6
80
50
38
22
17
48
97
29
72
5 
11
65
71

 sorted array is=>5 6 9 10 11 16 17 18 21 22 29 31 38 42 48 
 50 54 59 62 63 65 71 72 74 79 80 81 84 89 91 97
gescoe@gescoe-OptiPlex-3050:~$ 

*/




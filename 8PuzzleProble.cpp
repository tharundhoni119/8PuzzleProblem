#include <iostream>

using namespace std;

int A[3][3];
int g=1;
int h=0;
void print(int A[3][3])
{
      for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int heuristic(int A[3][3])
{
   
    int goal[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
        if(goal[i][j]!=A[i][j])
        {
            h++;
        }
        }
    }
    return h;
}

int main()
{

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>A[i][j];
        }
    }
    heuristic(A);
    if(h==0)
    {
        cout<<"Start State is the Goal State"<<endl;
    }
    print(A);
    while(h!=0)
    {
 
    if(A[0][0]==0)
    {
        A[0][0]=A[0][1];
        A[0][1]=0;
        int h1=heuristic(A);
        int f1=h1+g;
        A[0][1]=A[0][0];
        A[0][0]=0;
        
        A[0][0]=A[1][0];
        A[1][0]=0;
        
        
        int h2=heuristic(A);
        int f2=h2+g;
        if(f1>f2)
        {
          print(A); 
          h=h2;
        }
        else
        {
        A[0][0]=A[0][1];
        A[0][1]=0;
        print(A);
        h=h1;
        }
        g++;
    }
    else if(A[0][2]==0)
    {
        A[0][2]=A[0][1];
        A[0][1]=0;
        int h1=heuristic(A);
        int f1=h1+g;
        A[0][1]=A[0][2];
        A[0][2]=0;
        
        A[0][2]=A[1][2];
        A[1][2]=0;
        int h2=heuristic(A);
        int f2=h2+g;
        if(f1>f2)
        {
          print(A); 
          h=h2;
        }
        else
        {
        A[0][2]=A[0][1];
        A[0][1]=0;
        print(A);
        h=h1;
        }
        g++;
    }
    else if(A[2][0]==0)
    {
        A[2][0]=A[1][0];
        A[1][0]=0;
        int h1=heuristic(A);
        int f1=h1+g;
        A[1][0]=A[2][0];
        A[2][0]=0;
        
        A[2][0]=A[2][1];
        A[2][1]=0;
        int h2=heuristic(A);
        int f2=h2+g;
        if(f1>f2)
        {
          print(A); 
          h=h2;
        }
        else
        {
        A[2][0]=A[1][0];
        A[1][0]=0;
        print(A);
        h=h1;
        }
        g++;
    }
    else if(A[2][2]==0)
    {
        A[2][2]=A[1][2];
        A[1][2]=0;
        int h1=heuristic(A);
        int f1=h1+g;
        A[1][2]=A[2][2];
        A[2][2]=0;
        
        A[2][2]=A[2][1];
        A[2][1]=0;
        int h2=heuristic(A);
        int f2=h2+g;
        if(f1>f2)
        {
          print(A); 
          h=h2;
        }
        else
        {
        A[2][2]=A[1][2];
        A[1][2]=0;
        print(A);
        h=h1;
        }
        g++;
    }
    else if(A[0][1]==0)
    {
        A[0][1]=A[0][0];
        A[0][0]=0;
        int h1=heuristic(A);
        int f1=h1+g;
        A[0][0]=A[0][1];
        A[0][1]=0;
        
        A[0][1]=A[0][2];
        A[0][2]=0;
        int h2=heuristic(A);
        int f2=h2+g;
        A[0][2]=A[0][1];
        A[0][1]=0;
        
        A[0][1]=A[1][1];
        A[1][1]=0;
        int h3=heuristic(A);
        int f3=h3+g;
        if(f3<f2&&f3<f1)
        {
            print(A);
            h=h3;
        }
        else if(f2<f1&&f2<f3)
        {
            A[0][1]=A[0][2];
            A[0][2]=0;
            print(A);
            h=h2;
        }
        else
        {
            A[0][1]=A[0][0];
            A[0][0]=0;
            print(A);
            h=h1;
        }
        g++;
    }
    else if(A[1][0]==0)
    {
        A[1][0]=A[0][0];
        A[0][0]=0;
        int h1=heuristic(A);
        int f1=h1+g;
        A[0][0]=A[1][0];
        A[1][0]=0;
        
        A[1][0]=A[1][1];
        A[1][1]=0;
        int h2=heuristic(A);
        int f2=h2+g;
        A[1][1]=A[1][0];
        A[1][0]=0;
        
        A[1][0]=A[2][0];
        A[2][0]=0;
        int h3=heuristic(A);
        int f3=h3+g;
        if(f3<f2&&f3<f1)
        {
            print(A);
            h=h3;
        }
        else if(f2<f1&&f2<f3)
        {
            A[1][0]=A[1][1];
            A[1][1]=0;
            print(A);
            h=h2;
        }
        else
        {
            A[1][0]=A[0][0];
            A[0][0]=0;
            print(A);
            h=h1;
        }
        g++;
    }
    else if(A[2][1]==0)
    {
        A[2][1]=A[2][0];
        A[2][0]=0;
        int h1=heuristic(A);
        int f1=h1+g;
        A[2][0]=A[2][1];
        A[2][1]=0;
        
        A[2][1]=A[1][1];
        A[1][1]=0;
        int h2=heuristic(A);
        int f2=h2+g;
        A[1][1]=A[2][1];
        A[2][1]=0;
        
        A[2][1]=A[2][2];
        A[2][2]=0;
        int h3=heuristic(A);
        int f3=h3+g;
        if(f3<f2&&f3<f1)
        {
            print(A);
            h=h3;
        }
        else if(f2<f1&&f2<f3)
        {
            A[2][1]=A[1][1];
            A[1][1]=0;
            print(A);
            h=h2;
        }
        else
        {
            A[2][1]=A[2][0];
            A[2][0]=0;
            print(A);
            h=h1;
        }
        g++;
    }
    else if(A[1][2]==0)
    {
        A[1][2]=A[0][2];
        A[0][2]=0;
        int h1=heuristic(A);
        int f1=h1+g;
        A[0][2]=A[1][2];
        A[1][2]=0;
        
        A[1][2]=A[1][1];
        A[1][1]=0;
        int h2=heuristic(A);
        int f2=h2+g;
        A[1][1]=A[1][2];
        A[1][2]=0;
        
        A[1][2]=A[2][2];
        A[2][2]=0;
        int h3=heuristic(A);
        int f3=h3+g;
        if(f3<f2&&f3<f1)
        {
            print(A);
            h=h3;
        }
        else if(f2<f1&&f2<f3)
        {
            A[1][2]=A[1][1];
            A[1][1]=0;
            print(A);
            h=h2;
        }
        else
        {
            A[1][2]=A[0][2];
            A[0][2]=0;
            print(A);
            h=h1;
        }
        g++;
    }
    else if(A[1][1]=0)
    {
        A[1][1]=A[0][1];
        A[0][1]=0;
        int h1=heuristic(A);
        int f1=h1+g;
        A[0][1]=A[1][1];
        A[1][1]=0;
        
        A[1][1]=A[1][0];
        A[1][0]=0;
        int h2=heuristic(A);
        int f2=h2+g;
        A[1][0]=A[1][1];
        A[1][1]=0;
        
        A[1][1]=A[2][1];
        A[2][1]=0;
        int h3=heuristic(A);
        int f3=h3+g;
        A[2][1]=A[1][1];
        A[1][1]=0;
        
        A[1][1]=A[1][2];
        A[1][2]=0;
        int h4=heuristic(A);
        int f4=h4+g;
        if(h4<h3&&h4<h2&&h4<h1)
        {
            print(A);
            h=h4;
        }
        else if(h3<h4&&h3<h2&&h3<h1)
        {
            A[1][1]=A[2][1];
            A[2][1]=0;
            print(A);
            h=h3;
        }
        else if(h2<h1&&h2<h3&&h2<h4)
        {
            A[1][1]=A[1][0];
            A[1][0]=0;
            print(A);
            h=h2;
        }
        else
        {
         A[1][1]=A[0][1];
         A[0][1]=0;
         print(A);
         h=h1;
        }
        g++;
    }
    }
    
    
}


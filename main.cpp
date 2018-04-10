/*                      THE RUG PROBLEM
This program chooses two points on the straight lines on the rug
and depending on their type (with 2 or 3 intersecting lines) and their
distance from the edges, adds the number of unique triangles through
those points in the variable 'tri'
c -> y-coordinate of base point (Reference Point)
i -> y-coordinate of point under consideration
j -> common x-coordinate of the points (since the points are on the same straight line)

By: Ekansh Mahendru                                                       */

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int tri=0,m,n;
    cout<<"Rows <space> Columns \n";
    cin>>m>>n;
    for(int c=0; c<m; c++){
        for(int j=0; j<=n; j++){
            for(int i=c+1; i<=m; i++){
                if ((c+j)%2==0){         //Reference point having 3 intersecting lines
                    if((i+j)%2==0){      //PUC having 3 intersecting lines
                        if(j>=(i-c) && j<=n-(i-c))
                            tri+=8;      //Normal Case having 8 triangles
                        else if ((j>=ceil((i-c)/2) && j<=n-(i-c)) || (j>=(i-c) && j<=n-ceil((i-c)/2)))
                            tri+=4;      //When more than three quater of the largest triangle is visible
                        else if (j>=ceil((i-c)/2) && j<=n-ceil((i-c)/2))
                            tri+=2;      //When largest triangle is truncated from both sides
                        else if (j>=(i-c) || j<=n-(i-c))
                            tri+=3;      //When less than three quater of the largest triangle is visible
                        else if (j>=ceil((i-c)/2) || j<=n-ceil((i-c)/2))
                            tri+=1;      //When less than half of the largest triangle is visible
                    }
                    else{                //PUC having 2 intersecting lines
                        if(j>=(i-c) && j<=n-(i-c))
                            tri+=3;      //largest triangle fully visible
                        else if((i-c)>n)
                            continue;    //no triangle fully visible
                        else if ((j>=(i-c) && j>n-(i-c)) || (j<(i-c) && j<=n-(i-c)))
                            tri+=1;      //largest triangle partially visible


                    }
                }
                else{                     //Reference Point having 2 intersecting lines
                        if ((i+j)%2==0){  //PUC having 3 intersecting lines
                            if(j>=(i-c) && j<=n-(i-c))
                                tri+=3;   //largest triangle fully visible
                            else if((i-c)>n)
                                continue; //no triangle fully visible
                            else if ((j>=(i-c) && j>n-(i-c)) || (j<(i-c) && j<=n-(i-c)))
                                tri+=1;   //largest triangle partially visible


                        }
                    }
                }
            }

        }

    cout<<tri;
    return 0;
}

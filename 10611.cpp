#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

unsigned int height,chimp[51000];
int n,x,y,z,q,r;

int search() //mencari indeks chimp yang <= height
{
	int pivot;
	int kiri=1;
	int kanan=n;
	do
	{
		pivot=(kiri+kanan)/2;
		if((height==chimp[pivot])||((height>chimp[pivot])&&(height<chimp[pivot+1]))) return pivot;
			else if(height>chimp[pivot]) kiri=pivot+1;
				else if(height<chimp[pivot]) kanan=pivot-1;
	} while(kiri<=kanan);
	return -1;
}

int main()
{
	scanf("%d",&n);
	chimp[0]=0;
	for(x=1;x<=n;x++) scanf("%d",&chimp[x]);
	scanf("%d",&q);
	
	while(q--)
	{
		scanf("%d",&height);
		z=search();
		if(z!=-1) //height ada di jangkauan kumpulan chimps
		{
			int kiri = z;
			int kanan = z;
			while((chimp[kiri]>=height)&&(kiri>=1)) kiri--;
			while((chimp[kanan]<=height)&&(kanan<=n)) kanan++;

			if((kiri>=1)&&(kanan<=n)) printf("%d %d\n",chimp[kiri],chimp[kanan]);
				else if((kiri<1)&&(kanan>n))printf("X X\n");
					else if(kiri<1) printf("X %d\n",chimp[kanan]);
						else if(kanan>n) printf("%d X\n",chimp[kiri]);
		} else //height di luar jangkauan chimps
		
		{
			if(height>chimp[n]) printf("%d X\n",chimp[n]);
				else if(height<chimp[1]) printf("X %d\n",chimp[1]);
		}
	}
	return 0;
}

#include<iostream>
#include<map>
using namespace std;
map<pair<int,int>,bool>mp;
const int qua[6]={0,2,1,2,1,3};			// ��ͼ�е�6��������Ϊ4��
										// �����˳����ڸ�������
										// 0��㣬1��ׯ��2��ɽ��3�յ�
const int dist[6][6]={{0,7,8,9,9,11},	// 6�������֮��ľ������ 
					  {7,0,1,3,4,4},
					  {8,1,0,2,3,3},
					  {9,3,2,0,1,2},
					  {9,4,3,1,0,2},
					  {11,4,3,2,2,0}};
const int f[4][4]={{0,1,1,1},			// 6������㻥�ൽ��ľ������ 
				   {0,0,1,1},
				   {0,1,0,1},
				   {0,0,0,0}};
const int wea[30]={2,2,1,3,1,2,3,1,2,2,	// �������,1,2,3�ֱ�������ʡ����º�ɳ�� 
				   3,2,1,2,2,2,3,3,2,2,
				   1,1,2,1,3,2,1,1,2,2};
const int mx=3,my=2;					// mx��my�ֱ���ˮ��ʳ�������
const int cx=5,cy=10;					// cx��cy�ֱ���ˮ��ʳ��Ļ�׼�۸�
const int sx[4]={0,5,8,10};
							//sx���±�Ϊ1-3��Ԫ�طֱ�ָ����,����,ɳ��������ˮ�Ļ������� 
const int sy[4]={0,7,6,10};
							//sy���±�Ϊ1-3��Ԫ�طֱ�ָ����,����,ɳ��������ʳ��Ļ������� 
const int n=6;				// ����6������� 
const int maxm=1200;		// �������� 
const int coins=10000;		// ��ʼ���ʲ� 
const int base=1000;		// �ڿ�ÿ������ 
const int date=30;			// ��ֹ���� 
int costx[32][6][6];		// ��d��ӵ�i���ߵ���j�������ĵ�ˮ 
int costy[32][6][6];		// ��d��ӵ�i���ߵ���j�������ĵ�ʳ�� 
int days[32][6][6];			// ��d��ӵ�i���ߵ���j������Ҫ��ʵ������ 
int ans=0;
int rec[32];
// ÿһ��������ĵ�ı��-1�����ʱ�������·���ϵ�ĳ����ͨ����ʱ�Ѿ������յ�
// ��������� �ֱ����ǰ���λ�ڶ�Ӧ������� ��Ӧ�����qua������ʾ 
int act[32];
// ÿһ��������ж���� 2�����ڿ� 1�����ڿ�ɽֹͣ�ж� 0�����ڴ�ׯ���� 
int ansx[32];				// ansx��ansact�����Ž�·�������Ž�·���ϵ���Ϊ 
int ansact[32];
int ansg,ansh;				// ansg��ansh�����Ž��Ӧ�ĳ�ʼˮ��ʳ�����Դ�� 
int g,h;					// ����ö�ٵĳ�ʼˮ��ʳ����Դ�� 

void dfs(int day,int now,int nm,int c,int x,int y,int type)
{
	act[day]=type;
	rec[day]=now;
	
	if(qua[now]==3)
	{
		if(ans<=c+x*cx+y*cy)
		{
			ansg=g;
			ansh=h;
			ans=c+x*cx+y*cy;
			for(int i=0;i<=date;i++)
				ansx[i]=rec[i];
			for(int i=0;i<=date;i++)
				ansact[i]=act[i];
		}
		act[day]=-1;
		rec[day]=-1;
		return;
	}
	if(day>=date)
	{
		act[day]=-1;
		rec[day]=-1;
		return;
	}
	if(qua[now]==1)
		nm=maxm-mx*x-my*y;
	for(int i=0;i<n;i++)
		if(f[qua[now]][qua[i]])
		{
			int tx=costx[day][now][i];
			int ty=costy[day][now][i];
			int ucost=c;
			int ux,uy;
			int um=nm;
			if(x>=tx)
				ux=x-tx;
			else
			{
				ux=0;
				ucost-=2*(tx-x)*cx;
				um-=(tx-x)*mx;
			}
			
			if(y>=ty)
				uy=y-ty;
			else
			{
				uy=0;
				ucost-=2*(ty-y)*cy;
				um-=(ty-y)*my; 
			}
			if(ucost<0||um<0)
				continue;
			dfs(day+days[day][now][i],i,um,ucost,ux,uy,0);
		}
	if(qua[now]==2)
	{
		int attday=day;
		int tx=sx[wea[attday]];
		int ty=sy[wea[attday]];
		attday++;
		if(x>=tx)
		{
			x-=tx;
			tx=0;
		}
		else
		{
			tx-=x;
			x=0;
		}
		
		if(y>=ty)
		{
			y-=ty;
			ty=0;
		}
		else
		{
			ty-=y;
			y=0;
		}
		nm-=tx*mx+ty*my;
		c-=2*tx*cx+2*ty*cy;
		if(nm>=0&&c>=0)
			dfs(attday,now,nm,c,x,y,1);
		
		attday=day;
		tx=sx[wea[attday]]*2;
		ty=sy[wea[attday]]*2;
		attday++;
		if(x>=tx)
		{
			x-=tx;
			tx=0;
		}
		else
		{
			tx-=x;
			x=0;
		}
		
		if(y>=ty)
		{
			y-=ty;
			ty=0;
		}
		else
		{
			ty-=y;
			y=0;
		}
		nm-=tx*mx+ty*my;
		c-=2*tx*cx+2*ty*cy;
		c+=base;
		if(nm>=0&&c>=0)
			dfs(attday,now,nm,c,x,y,2);
	}
	rec[day]=-1;
	act[day]=-1;
}
int main()
{
	for(int d=0;d<=date;d++)
	{
		rec[d]=-1;
		act[d]=-1;
	}
	for(int d=0;d<date;d++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(f[qua[i]][qua[j]])
				{
					int now=0,count=0,sumx=0,sumy=0;
					while(count<dist[i][j])
					{
						if(wea[now+d]!=3)
						{
							count++;
							sumx+=2*sx[wea[now+d]];
							sumy+=2*sy[wea[now+d]];
						}
						else
						{
							sumx+=sx[wea[now+d]];
							sumy+=sy[wea[now+d]];
						}
						now++;
						if(now+d>=date)
							break;
					}
					if(count<dis[i][j])
					{
						sumx=sumy=20000;
						now=30;
					}
					costx[d][i][j]=sumx;
					costy[d][i][j]=sumy;
					days[d][i][j]=now;
				}
	for(int i=0;i<=maxm;i+=mx)
	{
		g=i/mx;
		h=(maxm-i)/my;
		if(!mp[make_pair(g,h)])
			dfs(0,0,0,coins-g*cx-h*cy,g,h,-1);
		mp[make_pair(g,h)]=1;
	}
	for(int i=0;i<=date;i++)
		cout<<i<<":"<<ansx[i]<<";"<<ansact[i]<<endl;
	cout<<endl;
	cout<<ans<<" "<<ansg<<" "<<ansh<<endl;
}

 

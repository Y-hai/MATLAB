#include<iostream>
#include<map>
using namespace std;
map<pair<int,int>,bool>mp;
const int qua[4]={0,1,2,3};				// ��ͼ�е�4��������Ϊ4��
										// �����˳����ڸ�������
										// 0��㣬1��ׯ��2��ɽ��3�յ�
const int dist[4][4]={{0,6,8,3},		// 4�������֮��ľ������ 
					  {6,0,2,3},
					  {8,2,0,5},
					  {3,3,5,0}};
const int f[4][4]={{0,1,1,1},			// 4������㻥�ൽ��ľ������ 
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
const int n=4;				// ����4������� 
const int maxm=1200;		// �������� 
const int coins=10000;		// ��ʼ���ʲ� 
const int base=1000;		// �ڿ�ÿ������ 
const int date=30;			// ��ֹ���� 
int costx[32][4][4];		// ��d��ӵ�i���ߵ���j�������ĵ�ˮ 
int costy[32][4][4];		// ��d��ӵ�i���ߵ���j�������ĵ�ʳ�� 
int days[32][4][4];			// ��d��ӵ�i���ߵ���j������Ҫ��ʵ������ 

int rec[32];				// ö�ٲ�ͬ�����ÿ������λ�ã��᲻�ϸ��� 
// ÿһ��������ĵ�ı��-1�����ʱ�������·���ϵ�ĳ����ͨ����ʱ�Ѿ������յ�
// ��������� �ֱ����ǰ���λ�ڶ�Ӧ������� ��Ӧ�����qua������ʾ 
int act[32];				// ö�ٲ�ͬ�����ÿ����ж����᲻�ϸ��� 
// ÿһ��������ж���� 2�����ڿ� 1�����ڿ�ɽֹͣ�ж� 0�����ڴ�ׯ���� 
int ansx[32];				// ansx��ansact�����Ž�·�������Ž�·���ϵ���Ϊ 
int ansact[32];
int ansg,ansh;				// ansg��ansh�����Ž��Ӧ�ĳ�ʼˮ��ʳ�����Դ�� 
int ans=0;					// ans�����洢ʣ���ʽ����������������� 
int g,h;					// ����ö�ٵĳ�ʼˮ��ʳ����Դ�� 

// day�������ڣ�now����ǰλ�ã�nm����ʣ��������c����ʣ���ʽ�����
// x����ˮ������y����ʳ��������type�����ж�(-1���������)��type�������ж�
void dfs(int day,int now,int nm,int c,int x,int y,int type)
{
	rec[day]=now;			// ����λ�� 
	act[day]=type;			// ����״̬ 
	// �����ǰ���յ�	
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
	// ���������ֹ���� 
	if(day>=date)
	{
		act[day]=-1;
		rec[day]=-1;
		return;
	}
	// �����ǰ�ڴ�ׯ 
	if(qua[now]==1)
		nm=maxm-mx*x-my*y;				// ����ʣ������ 
	for(int i=0;i<n;i++)
		if(f[qua[now]][qua[i]])
		{
			int tx=costx[day][now][i];	// ˮ�Ļ��� 
			int ty=costy[day][now][i];	// ʳ��Ļ��� 
			int ucost=c;				// c����ʣ���ʽ� 
			int ux,uy;					// ux,uy����ʣ��ˮ��ʳ������� 
			int um=nm;					// nm����ʣ������
			
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
	// �����ǰ�ڿ�ɽ 
	if(qua[now]==2)
	{
		int attday=day;					// �ȴ�һ�µ�ǰ���� 
		int tx=sx[wea[attday]];			// ��¼����ˮ�Ļ������� 
		int ty=sy[wea[attday]];			// ��¼����ʳ��Ļ������� 
		attday++;
		// �ж�ˮ����������������� 
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
		// �ж�ʳ�ﹻ��������������� 
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
		// ������ʱ�������⴦���Ǵ�ׯ��		
		nm-=tx*mx+ty*my;
		c-=2*tx*cx+2*ty*cy;
		if(nm>=0&&c>=0)
			dfs(attday,now,nm,c,x,y,1);
		
		attday=day;
		tx=sx[wea[attday]]*2;			// ��¼�����ڿ�ˮ������ 
		ty=sy[wea[attday]]*2;			// ��¼�����ڿ�ʳ������� 
		attday++;
		// �ж�ˮ�����������ڿ�����
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
		// �ж�ʳ�ﹻ���������ڿ�����
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
		// ������ʱ�������⴦���Ǵ�ׯ��
		nm-=tx*mx+ty*my;
		c-=2*tx*cx+2*ty*cy;
		c+=base;
		if(nm>=0&&c>=0)
			dfs(attday,now,nm,c,x,y,2);
	}
	// ���� 
	rec[day]=-1;
	act[day]=-1;
}
int main()
{	// ��ʼ��λ��������ж����� 
	for(int d=0;d<=date;d++)
	{
		rec[d]=-1;
		act[d]=-1;
	}
	// ��ʼ��costx,costy,days����ֻ���ĸ��� 
	for(int d=0;d<date;d++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(f[qua[i]][qua[j]]) 		// f�Ǿ��߾��� 
				{	// sumx��������ˮ��������sumy��������ʳ������� 
					int now=0,count=0,sumx=0,sumy=0;
					while(count<dist[i][j])
					{
						if(wea[now+d]!=3)	// ��Ϊɳ�� 
						{
							count++;		// count�������߾��� 
							sumx+=2*sx[wea[now+d]];
							sumy+=2*sy[wea[now+d]];
						}
						else
						{
							sumx+=sx[wea[now+d]];
							sumy+=sy[wea[now+d]];
						}
						now++;				// now��������ʱ�� 
						if(now+d>=date)		// d����ǰ���� 
							break;
					}
					// ��d���i�߲���j����� 
					if(count<dist[i][j])
					{
						sumx=sumy=20000;	// ��㸳ֵ������������������ 
						now=30;				// ��㸳ֵ������29���� 
					}
					costx[d][i][j]=sumx;	// ����ʳ����
					costy[d][i][j]=sumy;	// ����ˮ��
					days[d][i][j]=now;		// �������� 
				}

	// ö��ˮռ������ 
	for(int i=0;i<=maxm;i+=mx)
	{	// g,h�����ʼˮ��ʳ������� 
		g=i/mx;						// ˮ������������ȡ�� 
		h=(maxm-i)/my;				// ʳ������������ȡ�� 
		if(!mp[make_pair(g,h)])		// ��������ݹ������������ͽ��еݹ� 
			dfs(0,0,0,coins-g*cx-h*cy,g,h,-1);
		mp[make_pair(g,h)]=true;	// �������͸�Ϊtrue 
	}

	// ansx��������λ�ã�ansact����ǰ�ж� 
	for(int i=0;i<=date;i++)
		cout<<i<<":"<<ansx[i]<<";"<<ansact[i]<<endl;
	cout<<endl;
	cout<<ans<<" "<<ansg<<" "<<ansh<<endl;
}

 

%% ɳ������
clear;clc;
x=0:200:1800;
y=x';
z=[2000,2000,2001,1992,1954,1938,1972,1995,1999,1999;
   2000,2002,2006,1908,1533,1381,1728,1959,1998,2000;
   2000,2005,2043,1921,977, 897, 1310,1930,2003,2000;
   1997,1978,2009,2463,2374,1445,1931,2209,2050,2003;
   1992,1892,1566,1971,2768,2111,2653,2610,2121,2007;
   1991,1875,1511,1556,2221,1986,2660,2601,2119,2007;
   1996,1950,1797,2057,2849,2798,2608,2303,2052,2003;
   1999,1999,2079,2685,3390,3384,2781,2165,2016,2000;
   2000,2002,2043,2271,2668,2668,2277,2049,2003,2000;
   2000,2000,2004,2027,2067,2067,2027,2004,2000,2000];
surf(x,y,z);
x1=0:100:1800;
y1=x1';
z1=interp2(x,y,z,x1,y1,'spline');
surf(x1,y1,z1);
x2=0:50:1800;
y2=x2';
z2=interp2(x,y,z,x2,y2,'spline');
surf(x2,y2,z2);
% ���Ƶȸ���ͼ�����һ�����������㼶
contour(x2,y2,z2,12);
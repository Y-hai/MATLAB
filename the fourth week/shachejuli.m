%% ɲ����������
clear;cla;
v=20:10:150;
d2=[3.15,7.08,12.59,19.68,28.34,38.57,50.4,63.75,78.71,95.22,113.29,132.93,154.12,176.87];
vs=v*(1000/3600);
d1=vs*10;
d3=10;
d=d1+d2+d3;
vi=20:150;
F=griddedInterpolant(v,d,'spline');
di=F(vi);
%di=interp1(v,d,vi,'spline');
x=abs(di-120);
[y,i]=sort(x);
vi(i(1));
plot(vi,di,vi(i(1)),di(i(1)),'rp');
hold on;
%�������ڶ���
j=find(vi==125);
plot(vi,di,125,di(j),'rp');
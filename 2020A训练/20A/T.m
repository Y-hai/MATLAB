function result = T(RC1,RC2,v,T1,T2,T3,T4,h)
% ���PCB�������¶ȱ仯����
% RC1��RC2��������ʱ�䳣����v���ƶ��ٶȣ�Ti����i���������¶ȣ�h����������ϵ����
deltat=0.01;
len1=floor(339.5/v/deltat);
len0=floor(235.5/v/deltat);
len=floor(435.5/v/deltat);
tn=zeros(1,len);
for i=1:len
    tn (i)=i*deltat;
end
T=ones(1,25)*25;
for i=2:len0
    T(i)=T(i-1)+(F(tn(i),v,T1,T2,T3,T4)-T(i-1))*(1-exp(-deltat/RC1));
end
for i=len0+1:len1
    T(i)=T(i-1)+(F(tn(i),v,T1,T2,T3,T4)-T(i-1))*(1-exp(-deltat/RC2));
end

for i=len1+1:len
    T(i)=T(i-1)+(F(tn(i),v,T1,T2,T3,T4)-T(i-1))*h*deltat;
end
result=T;
end


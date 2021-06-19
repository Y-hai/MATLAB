function gm(A)
syms a b;
c=[a b]';
B=cumsum(A);  % ԭʼ�����ۼ�
n=length(A);
for i=1:(n-1)
    C(i)=(B(i)+B(i+1))/2;  % �����ۼӾ���
end
% �������������ֵ
D=A;D(1)=[];
D=D';
E=[-C;ones(1,n-1)];
c=inv(E*E')*E*D;
c=c';
a=c(1);b=c(2);
% Ԥ���������
F=[];F(1)=A(1);
for i=2:(n+12)
    F(i)=(A(1)-b/a)/exp(a*(i-1))+b/a ;
end
G=[];G(1)=A(1);
for i=2:(n+12)
    G(i)=F(i)-F(i-1); %�õ�Ԥ�����������
end 
t1=1:48;
t2=1:60;
G, a, b % ���Ԥ��ֵ����չϵ���ͻ�ɫ������

% ��ɫԤ��
subplot(1,2,1);
plot(t1,A,'ko', 'LineWidth',2)
hold on
grid on
plot(t2,G,'k', 'LineWidth',2)
xlabel('�·�', 'fontsize',12)
ylabel('�Ӿ���','fontsize',12)
set(gca,'LineWidth',2);
% �������
subplot(1,2,2);
p=polyfit(t1,A,2);
plot(t1,A,'ko',t2,polyval(p,t2),'k','LineWidth',2);
hold on
grid on
xlabel('�·�', 'fontsize',12)
ylabel('�Ӿ���','fontsize',12)
set(gca,'LineWidth',2);
end


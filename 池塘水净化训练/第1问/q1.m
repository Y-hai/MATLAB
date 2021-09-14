%% 
clear;clc
name='person���ϵ��.xls';
X1=xlsread(name,'Sheet1','A2:L121');
X2=xlsread(name,'Sheet2','A2:L121');

% ������120��������������JB����
c = size(X1,2);     % ���ݵ�����
H = zeros(1,c);     % ��ʼ����ʡʱ�������
P = zeros(1,c);
for i = 1:c
    [h,p] = jbtest(X1(:,i),0.05);   % hΪ1����ܾ�ԭ����
    H(i)=h;
    P(i)=p;         % P����pֵ
end
disp(H)
disp(P)

% ������ضȺ�������ˮƽ
[R1,P1]=corr(X1,'type','Spearman');
R1(:,2:2:end)=[];
R1(1:2:end,:)=[];
P1(:,2:2:end)=[];
P1(1:2:end,:)=[];
[R2,P2]=corr(X2,'type','Spearman');
R2(:,2:2:end)=[];
R2(1:2:end,:)=[];
P2(:,2:2:end)=[];
P2(1:2:end,:)=[];
% xlswrite(name,R1,'Sheet3','B2');
% xlswrite(name,R2,'Sheet4','B2');

% �����Ա��

P1 < 0.01                   % ���3���ǵ�λ��
(P1 < 0.05) .* (P1 > 0.01)  % ���2���ǵ�λ��
(P1 < 0.1) .* (P1 > 0.05)	% ���1���ǵ�λ��

P2 < 0.01                   % ���3���ǵ�λ��
(P2 < 0.05) .* (P2 > 0.01)  % ���2���ǵ�λ��
(P2 < 0.1) .* (P2 > 0.05)   % ���1���ǵ�λ��
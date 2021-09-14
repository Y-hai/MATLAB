%% ��ɫ����������
clear;clc
name = '1989�����ɽ�����5�������󾮼�������ָ��ʵ��ֵ.xlsx';
X = readmatrix(name,'Range','B2:F10');

%% ��׼��
B = X;
% ���򻯳ɱ���ָ��
for x = [1 5 7 9]
    M = max(X(x,:))*2;
    B(x,:) = (M-X(x,:));
end
disp('��׼����ľ���');
disp(B);

%% ��Ȩ������Ȩ��
P = B./repmat(sum(B,2),1,5);
disp('ָ��Ȩ���������£�');
weight = shangquan(P)

%% ����ĸ���к������У�X��Y�ֱ������ĸ����
% ���ﲻ���ù�һ��������м���
Y = max(B,[],2);
X = B;

%% �����ɫ��Ȩ������
absX0_Xi = abs(X - repmat(Y,1,size(X,2)))   % ����|X0-Xi|����
disp('������С�');
a = min(min(absX0_Xi))  % ����������С��a
disp('�������');
b = max(max(absX0_Xi))  % ������������b
rho = 0.5;              % �ֱ�ϵ��ȡ0.5����
disp('��ɫ����ϵ��');
gamma = (a+rho*b) ./ (absX0_Xi  + rho*b)    % �����ɫ����ϵ��
score = sum(gamma .* repmat(weight,1,5));
stand_S = score / sum(score);               % ��һ��
writematrix(stand_S,name,'Range','B11');
disp('���������£�');
[sorted_S,index] = sort(stand_S ,'descend') % ����
huitu(1:5, stand_S);

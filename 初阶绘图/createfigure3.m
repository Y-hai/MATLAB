function createfigure3(X1, Y1)
%CREATEFIGURE3(X1, Y1)
%  X1:  x ���ݵ�����
%  Y1:  y ���ݵ�����

%  �� MATLAB �� 02-Apr-2021 18:51:39 �Զ�����

% ���� figure
figure1 = figure('Color',[1 1 1]);

% ���� axes
axes1 = axes('Parent',figure1);
hold(axes1,'on');

% ���� plot
plot(X1,Y1,'DisplayName','data1');

% ȡ�������е�ע���Ա����������� X ��Χ
% xlim(axes1,[0 7]);
% ȡ�������е�ע���Ա����������� Y ��Χ
% ylim(axes1,[-0.990651475314052 1.00934852468595]);
box(axes1,'on');
% ���� legend
legend(axes1,'show');


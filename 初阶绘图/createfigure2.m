function createfigure2(x,y1)
%CREATEFIGURE2(y1)
%  Y1:  y ���ݵ�����

%  �� MATLAB �� 02-Apr-2021 18:46:36 �Զ�����

% ���� figure
figure1 = figure('Color',[1 1 1]);

% ���� axes
axes1 = axes('Parent',figure1);
hold(axes1,'on');

% ���� plot
plot(x,y1,'DisplayName','y');

box(axes1,'on');
% ���� legend
legend(axes1,'show');


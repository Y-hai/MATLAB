function createfigure(X1, Y1)
%CREATEFIGURE(X1, Y1)
%  X1:  x ���ݵ�����
%  Y1:  y ���ݵ�����

%  �� MATLAB �� 02-Apr-2021 18:03:54 �Զ�����

% ���� figure
figure1 = figure('Color',...
    [0.894117653369904 0.941176474094391 0.901960790157318]);

% ���� axes
axes1 = axes('Parent',figure1,...
    'Position',[0.128751560549313 0.106951219512195 0.775 0.815]);
hold(axes1,'on');

% ���� plot
plot(X1,Y1,'ZDataSource','','Color',[0 0 0]);

% ���� xlabel
xlabel('x','LineStyle','none','EdgeColor',[1 1 1],...
    'HorizontalAlignment','right',...
    'FontSize',11);

% ���� title
title('y = sin(x)');

% ȡ�������е�ע���Ա����������� X ��Χ
% xlim(axes1,[0 6.29]);
box(axes1,'on');
% ������������������
set(axes1,'Color',[0.894117653369904 0.941176474094391 0.901960790157318],...
    'FontName','���Ŀ���','FontWeight','bold','XAxisLocation','origin','XColor',...
    [0 0 0],'XGrid','on','XTick',[0 3.1415926 6.2831852 6.29],'XTickLabel',...
    {'0','\pi','2\pi',''},'YColor',[0 0 0],'YGrid','on','ZColor',[0 0 0]);

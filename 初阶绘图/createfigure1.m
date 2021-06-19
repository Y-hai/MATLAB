function createfigure1(x1, y1)
%CREATEFIGURE1(x1, y1)
%  X1:  x ���ݵ�����
%  Y1:  y ���ݵ�����

%  �� MATLAB �� 02-Apr-2021 18:17:56 �Զ�����

% ���� figure
figure1 = figure('InvertHardcopy','off','Color',[1 1 1]);

% ���� axes
axes1 = axes('Parent',figure1,...
    'Position',[0.128751560549313 0.106951219512195 0.775 0.815]);
hold(axes1,'on');

% ���� plot
plot(x1,y1,'ZDataSource','','DisplayName','y=sin(x)','LineWidth',1,...
    'Color',[0.0705882385373116 0.211764708161354 0.141176477074623]);

% ���� ylabel
ylabel({'y'},'FontWeight','bold','FontSize',11,'Rotation',0);

% ���� xlabel
xlabel('x','LineStyle','none','EdgeColor',[1 1 1],...
    'HorizontalAlignment','right',...
    'FontSize',11);

% ���� title
title('y = sin(x)','HorizontalAlignment','center','FontWeight','bold',...
    'FontSize',11);

% ȡ�������е�ע���Ա����������� X ��Χ
% xlim(axes1,[0 6.29]);
% ȡ�������е�ע���Ա����������� Y ��Χ
% ylim(axes1,[-1 1]);
% ȡ�������е�ע���Ա����������� Z ��Χ
% zlim(axes1,[-1 1]);
box(axes1,'on');
% ������������������
set(axes1,'Color',[0.894117653369904 0.941176474094391 0.901960790157318],...
    'FontName','���Ŀ���','FontWeight','bold','XAxisLocation','origin','XColor',...
    [0 0 0],'XGrid','on','XTick',[0 1.57 3.14 4.71 6.28 6.29],'XTickLabel',...
    {'0','1/2\pi','\pi','3/2\pi','\pi',''},'YColor',[0 0 0],'YGrid','on',...
    'ZColor',[0 0 0]);
% ���� legend
legend(axes1,'show');


function volume = pillar(Do,Di,height)
%UNTITLED2 �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
if nargin==2
    height=1;
end
volume=abs(Do.^2-Di.^2).*height*pi/4;
end


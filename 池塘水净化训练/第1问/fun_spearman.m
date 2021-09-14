%% ����spearman���ϵ����������ˮƽP,��������n>30�Ĵ�����
% û��MATLAB�Դ��ĺ���׼
function [R,P] = fun_spearman(X,kind)

    % �жϲ���������Ĭ��˫β����
    if nargin == 1
        kind = 2;
    end
    
    % ����ȼ�����D
    [r,c]=size(X);
    [~,D]=sort(X);
    [~,D]=sort(D);
    % ����ͬ�����ݵȼ����д���
    for i=1:c
        DX=D(:,i);
        for j=1:r
            a=(X(:,i)==X(j,i));         % �õ��߼�����a
            DX(a==1)=sum(DX.*a)/sum(a); % �����ν��д���
        end
        D(:,i)=DX;
    end
    
    % �������ϵ��R
    R=eye(c);
    for i=1:c-1
        for j=i+1:c
%             R(i,j)=1-6*sum((D(:,i)-D(:,j)).^2)/(r*(r*r-1));
            % ���������׼ȷһЩ�����ʻ���Ƥ��ѷ���ϵ��
            a=corrcoef(D(:,i),D(:,j));
            R(i,j)=a(1,2);
            R(j,i)=R(i,j);
        end
    end
    
    % �������
    if kind~=1 && kind~=2
        disp('Kind�����������������ˮƽP����ʧ��')
    else
        P=eye(c); % ��ʼ��
        for i=1:c-1
            for j=i+1:c
                z=abs(R(i,j))*sqrt(r-1);
                P(i,j)=(1-normcdf(z))*kind;
                P(j,i)=P(i,j);
            end
        end
    end

end


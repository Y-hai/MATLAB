function binPop=m_Coding(pop,pop_length,irange_l)
%% �����Ʊ��루����Ⱦɫ�壩
% ���룺pop--��Ⱥ
%      pop_length--���볤��
pop=round((pop-irange_l)*10^6);
for n=1:size(pop,2) %ѭ��
        dec2binpop{n}=dec2bin(pop(n));%dec2bin�����Ϊ�ַ�������
        lengthpop=length(dec2binpop{n});%dec2binpop��cell����
        for s=1:pop_length-lengthpop %����
            dec2binpop{n}=['0' dec2binpop{n}];
        end
    binPop{n}=dec2binpop{n};   %ȡdec2binpop�ĵ�1��
end

    
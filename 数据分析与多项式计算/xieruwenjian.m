%%������ļ�
data=[5 1 1;3 7 4];
[row,col]=size(data); %����������������
%���ļ��������ֱ�Ӵ򿪣����û�оͻ��´���һ��
%���û��ָ��·������ôΪ��ǰmatlab·��
fid=fopen('test.txt','wt');   %��д
for i=1:row
    for j=1:col
        fprintf(fid,'%d',data(i,j));
    end
    fprintf(fid,'\n');
end
fprintf(fid,'Hello world!\n');
fprintf(fid,'%x',hex2dec('ABCD'));
fclose(fid); %�����ǹرմ򿪵��ļ�
%%
clear;
opts = spreadsheetImportOptions("NumVariables", 2);
opts.Sheet = "Sheet1";
opts.DataRange = "B2:C3684";
opts.VariableNames = ["VarName2", "VarName3"];
opts.VariableTypes = ["string", "double"];
opts = setvaropts(opts, "VarName2", "WhitespaceRule", "preserve");
opts = setvaropts(opts, "VarName2", "EmptyFieldRule", "auto");
t = readtable("附件2：某地消防救援出警数据.xlsx", opts, "UseExcel", false);
clear opts
data=zeros(3682,2);
a=zeros(5,12);
n=height(t);
for i=1:n
    s=split(t{i,1},"-");
    data(i,1)=str2double(s(1));
    data(i,2)=str2double(s(2));
    a(data(i,1)-2015,data(i,2))=a(data(i,1)-2015,data(i,2))+1;
end
clear i n s t data;
A=[a(1,:),a(2,:),a(3,:),a(4,:)];
areasum=sum(a);
gm(A)
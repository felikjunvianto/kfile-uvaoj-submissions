var x:longint;
	num:array[0..1000000] of longint;
	
function f(x:longint):longint;
	
	begin
		if num[x]=0 then num[x]:=(f(trunc(x-sqrt(x)))+f(trunc(ln(x)))+f(trunc(x*sin(x)*sin(x)))) mod 1000000;
		f:=num[x];
	end;
	
begin
	fillchar(num,sizeof(num),0);
	num[0]:=1;
	repeat
		readln(x);
		if x<>-1 then writeln(f(x));
	until x = -1;
end.
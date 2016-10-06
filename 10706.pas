var t,x,y,n,count,temp:longint;
	baris:ansistring;
	semen:string;
	
function big(var x:longint;max:longint):longint;
	begin
		if x>max then
		begin
			big:=max;
			x:=x-max;
		end else
		begin
			big:=x;
			x:=0;
		end;
	end;
	
begin
	readln(t);
	for x:=1 to t do
	begin
		readln(n);
		count:=0;
		repeat
			inc(count);
			temp:=count;
			n:=n-(big(temp,9)*1+big(temp,90)*2+big(temp,900)*3+big(temp,9000)*4+big(temp,90000)*5+big(temp,900000)*6);
		until n<=0;
		temp:=count;
		n:=n+(big(temp,9)*1+big(temp,90)*2+big(temp,900)*3+big(temp,9000)*4+big(temp,90000)*5+big(temp,900000)*6);
		
		baris:='';
		for y:=1 to count do 
		begin
			str(y,semen);
			baris:=baris+semen;
		end;
		writeln(baris[n]);
	end;
end.
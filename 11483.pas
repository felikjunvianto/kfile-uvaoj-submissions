var n,x,y,z:longint;
	hasil:string;
	
begin
	z:=0;
	repeat
		readln(n);
		if n>0 then
		begin
			inc(z);
			writeln('Case ',z,':');
			writeln('#include<string.h>');
			writeln('#include<stdio.h>');
			writeln('int main()');
			writeln('{');
			
			for x:=1 to n do
			begin
				readln(hasil);
				write('printf("');
				for y:=1 to length(hasil) do if((hasil[y]='"') or(hasil[y]='\')) then write('\',hasil[y]) else write(hasil[y]);
				writeln('\n");');
			end;
			writeln('printf("\n");');
			writeln('return 0;');
			writeln('}');
		end;
	until n=0;
end.
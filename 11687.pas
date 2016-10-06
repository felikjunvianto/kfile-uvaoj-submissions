var x,y,z,temp:longint;
	test:array[1..1000] of string;
	hasil:array[0..1000] of string;
	
begin
	x:=0;
	repeat
		inc(x);
		readln(test[x]);
	until test[x]='END';
	dec(x);
	
	for y:=1 to x do
	begin
		hasil[0]:=test[y];
		z:=0;
		repeat
			inc(z);
			temp:=length(hasil[z-1]);
			str(temp,hasil[z]);
		until hasil[z]=hasil[z-1];
		writeln(z);
	end
end.
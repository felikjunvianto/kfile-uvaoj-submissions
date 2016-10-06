var n,x,y,count,banyak,z,temp:longint;
	train:array[1..50] of longint;
	
begin
	readln(n);
	for x:=1 to n do
	begin
		readln(banyak);
		for y:=1 to banyak do read(train[y]);
		readln;
		count:=0;
		
		for y:=1 to banyak-1 do
			for z:=y+1 to banyak do if train[z]<train[y] then
			begin
				inc(count);
				temp:=train[z];
				train[z]:=train[y];
				train[y]:=temp;
			end;
			
		writeln('Optimal train swapping takes ',count,' swaps.');
	end;
end.
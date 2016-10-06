var n,x,y:longint;
	command_a,command_b:string[4];
	dummy:char;
	a,b,c:longint;
	tinggi,posisi:array[0..25] of longint;
	tumpuk:array[0..25,1..26] of longint;
	
begin
	readln(n);
	for x:=0 to n-1 do 
	begin
		tinggi[x]:=1;
		posisi[x]:=x;
		tumpuk[x,1]:=x;
	end;
	repeat
		read(command_a);
		if command_a='quit' then readln else
		begin
			readln(a,dummy,command_b,b);
			if posisi[a]<>posisi[b] then
			begin
				if command_b='onto' then
				begin
					for x:=1 to tinggi[posisi[b]] do if tumpuk[posisi[b],x]=b then break;
					for y:=x+1 to tinggi[posisi[b]] do 
					begin
						tinggi[tumpuk[posisi[b],y]]:=1;
						tumpuk[tumpuk[posisi[b],y],1]:=tumpuk[posisi[b],y];
						posisi[tumpuk[posisi[b],y]]:=tumpuk[posisi[b],y];
					end;
					tinggi[posisi[b]]:=x;
				end;
	
				for x:=1 to tinggi[posisi[a]] do if tumpuk[posisi[a],x]=a then break;
				if command_a='move' then
				begin
					for y:=x+1 to tinggi[posisi[a]] do 
					begin
						tinggi[tumpuk[posisi[a],y]]:=1;
						tumpuk[tumpuk[posisi[a],y],1]:=tumpuk[posisi[a],y];
						posisi[tumpuk[posisi[a],y]]:=tumpuk[posisi[a],y];
					end;
					tinggi[posisi[a]]:=x-1;
					inc(tinggi[posisi[b]]);
					tumpuk[posisi[b],tinggi[posisi[b]]]:=a;
				end else
				
				if command_a='pile' then
				begin
					c:=posisi[a];
					for y:=x to tinggi[c] do
					begin
						tumpuk[posisi[b],tinggi[posisi[b]]+y-x+1]:=tumpuk[c,y];
						posisi[tumpuk[c,y]]:=posisi[b];
					end;
					inc(tinggi[posisi[b]],tinggi[c]-x+1);
					tinggi[c]:=x-1;
				end;
			end;
			posisi[a]:=posisi[b];
		end;
	until command_a='quit';
	
	for x:=0 to n-1 do
	begin
		write(x,':');
		for y:=1 to tinggi[x] do write(' ',tumpuk[x,y]);
		writeln;
	end;
end.
	
	
var x,y,n,z:longint;
	rela:array[1..500] of longint;

function result(rumah:longint):longint;
	var hasil:longint;
	begin
		hasil:=0;
		for z:=1 to y do hasil:=hasil+abs(rela[z]-rumah);
		result:=hasil;
	end;
	
procedure quick(terkiri,terkanan:integer);
	var kiri,kanan:integer;
		temp,pivot:longint;
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=rela[(kiri+kanan) div 2];
			while kiri<=kanan do
			begin
				while rela[kiri] < pivot do inc(kiri);
				while rela[kanan] > pivot do dec(kanan);
			
				if kiri<=kanan then
				begin
					temp:=rela[kiri];
					rela[kiri]:=rela[kanan];
					rela[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			quick(terkiri,kanan);
			quick(kiri,terkanan);
		end;
	end;
	
begin
	readln(n);
	for x:=1 to n do
	begin
		fillchar(rela,sizeof(rela),0);
		read(y);
		for z:=1 to y-1 do read(rela[z]);
		readln(rela[y]);
		quick(1,y);
		
		if odd(y) then writeln(result(rela[(y div 2)+1])) else 
			if (result(rela[y div 2]) > result(rela[(y div 2)+1])) then writeln(result(rela[(y div 2)+1])) else writeln(result(rela[y div 2]));
	end;
end.
	
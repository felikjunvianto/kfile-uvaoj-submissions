var x,y,z,count:longint;
	baca:string;
	list:array[1..2000] of string;

procedure quicksort(terkiri,terkanan:longint);
	var kiri,kanan:longint;
		temp,pivot:string;
		
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=list[(kiri+kanan) div 2];
			
			while kiri<=kanan do
			begin
				while list[kiri]<pivot do inc(kiri);
				while list[kanan]>pivot do dec(kanan);
				
				if kiri<=kanan then
				begin
					temp:=list[kiri];
					list[kiri]:=list[kanan];
					list[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			quicksort(terkiri,kanan);
			quicksort(kiri,terkanan);
		end;
	end;
	
begin
	readln(x);
	for y:=1 to x do
	begin
		readln(baca);
		z:=pos(' ',baca);
		list[y]:=copy(baca,1,z-1);
	end;
	quicksort(1,x);
	
	y:=0;
	repeat
		inc(y);
		z:=y+1;
		count:=1;
		while((z<=x) and (list[y]=list[z])) do 
		begin
			inc(z);
			inc(count);
		end; 
		writeln(list[y],' ',count);
		dec(z);
		y:=z;
	until y>=x;
end.
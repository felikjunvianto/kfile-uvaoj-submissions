type data=record
	 kar:char;
	 count:longint;
	 end;
	 
var x,y,n:longint;
	kasus:ansistring;
	temp:array['A'..'Z'] of longint;
	jalan:char;
	bersih:array[1..26] of data;
	
procedure sort(terkiri,terkanan:longint);
	var kiri,kanan,pivot:longint;
		temp:data;
		
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=bersih[(kiri+kanan) div 2].count;
			
			while kiri<=kanan do
			begin
				while bersih[kiri].count>pivot do inc(kiri);
				while bersih[kanan].count<pivot do dec(kanan);
				if kiri<=kanan then
				begin
					temp:=bersih[kiri];
					bersih[kiri]:=bersih[kanan];
					bersih[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			sort(terkiri,kanan);
			sort(kiri,terkanan);
		end;
	end;
	
procedure sortsama(terkiri,terkanan:longint);
	var kiri,kanan:longint;
		pivot:char;
		temp:data;
		
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=bersih[(kiri+kanan) div 2].kar;
			
			while kiri<=kanan do
			begin
				while bersih[kiri].kar<pivot do inc(kiri);
				while bersih[kanan].kar>pivot do dec(kanan);
				if kiri<=kanan then
				begin
					temp:=bersih[kiri];
					bersih[kiri]:=bersih[kanan];
					bersih[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			sortsama(terkiri,kanan);
			sortsama(kiri,terkanan);
		end;
	end;
	
procedure ceksama(awal,akhir:longint);
	var x:longint;
	
	begin
		dec(awal);
		repeat
			inc(awal);
			x:=awal+1;
			while((bersih[x].count=bersih[awal].count)and(x<=akhir)) do inc(x);
			dec(x);
			sortsama(awal,x);
			awal:=x;
		until awal>=akhir;
	end;
	
begin
	fillchar(temp,sizeof(temp),0);
	readln(n);
	for x:=1 to n do
	begin
		readln(kasus);
		for y:=1 to length(kasus) do 
			if ((ord(upcase(kasus[y]))>=65) and (ord(upcase(kasus[y]))<=90)) then inc(temp[upcase(kasus[y])]);
	end;
	
	x:=0;
	for jalan:='A' to 'Z' do 
		if temp[jalan]>0 then
		begin
			inc(x);
			bersih[x].kar:=jalan;
			bersih[x].count:=temp[jalan];
		end;
		
	sort(1,x);
	ceksama(1,x);
	
	for y:=1 to x do writeln(bersih[y].kar,' ',bersih[y].count);
end.
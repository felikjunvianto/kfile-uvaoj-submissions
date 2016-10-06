type petani=record
	 luas,hewan,premium:longint;
	 end;
	 
var x,y,z,a,hasil:longint;
	farmer:petani;
	
begin
	readln(x);
	for y:=1 to x do
	begin
		hasil:=0;
		readln(z);
		for a:=1 to z do 
		begin
			readln(farmer.luas,farmer.hewan,farmer.premium);
			hasil:=hasil+(farmer.luas*farmer.premium);
		end;
		writeln(hasil);
	end;
end.
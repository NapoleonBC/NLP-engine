
# AUTOMATICALLY GENERATED! EDITS WILL BE LOST!
# FILE: d:\apps\corporate\spec\company.pat
# TIME: 16:07:29 05/14/01
@NODES _sentence

@PRE
<1,1>	cap();
<2,2>	cap();
@RULES

# Ex:	MD\_Files
_company <- MD [s] Files [s] @@

@PRE
<1,1>	cap();
<2,2>	cap();
<3,3>	cap();
@RULES

# Ex:	New\_Hampshire\_Medical
_company <- New [s] Hampshire [s] Medical [s] @@

@PRE
<1,1>	cap();
<2,2>	cap();
@RULES

# Ex:	Carezani\_Med
_company <- Carezani [s] Med [s] @@

@PRE
<1,1>	cap();
<1,1>	length(3);
<2,2>	cap();
<2,2>	length(9);
<3,3>	cap();
<3,3>	length(7);
@RULES

# Ex:	New\_Hampshire\_Medical
_company <- New [s] Hampshire [s] Medical [s] @@


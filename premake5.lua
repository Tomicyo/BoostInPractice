  solution "BoostInPractice"
	
	act = ""
    
    if _ACTION then
        act = _ACTION
    end

   	configurations { "Debug", "Release" }

	postfix=""
	
	targetdir "../Bin"
	location("./" .. act .. postfix)

	projectRootDir = os.getcwd() 
	print("Project root directroy: " .. projectRootDir);
	
	language "C++"
	include "object_pool"
	
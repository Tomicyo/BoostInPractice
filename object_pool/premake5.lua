project "object_pool"
   kind "ConsoleApp"
   language "C++"

   defines {
      "MAC_OSX=1"
   }

   includedirs { "/usr/local/Cellar/boost/1.60.0_1/include" }
   libdirs { "/usr/local/Cellar/boost/1.60.0_1/lib" }
   links { "boost_system" }
   buildoptions "-std=c++14 -stdlib=libc++"

   files { 
      "object_pool.cpp"
   }

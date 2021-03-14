// OpenScad special variables
$fn = 50;

//Lego brick parameters

brick_width = 15.8;
brick_length = 31.8;
brick_height = 9.6;

cyl_diameter = 4.8;
cyl_height = 1.8;
number_cyl = 4;

// Step 3
brick_wall = 1.2;

// Step 4
number_cyl = 4;
// Step 6
minicyl_diameter = 2.6;

// Step 10 - Int cyl
intcyl_diameter = 6.5;
intcyl_diameter2 = 4.8;
// End parameters

module lego_brick(){

    // 3D Model
    // Boolean Operator
    union(){ // Lego Piece
        color("red")
         difference(){ // Cube walls

                cube([brick_width, brick_length,brick_height],center=false);


                translate([brick_wall,brick_wall,-brick_wall])
                cube([brick_width-brick_wall*2, brick_length-brick_wall*2,brick_height-brick_wall],center=false);
            }

            // Top Cyl
        for (a =[0:number_cyl-1]){
color("red")
                        // Step 2
                        translate([3.9,(3.9+(8*a)),brick_height])
                        cylinder( h = cyl_height, d=cyl_diameter, center = true);

             color("red")             // Step 4
                        translate([3.9+8,(3.9+(8*a)),brick_height])
                        cylinder( h = cyl_height, d=cyl_diameter, center = true);
                 }

          // Internal Cyl
           color("red")
         for (a =[0:number_cyl-2]){
            translate([brick_width/2,8+8*a,-0.2])
                difference(){

                    cylinder( h = brick_height, d=intcyl_diameter, center = false);
                    translate([0,0,-brick_wall])
                    cylinder( h = brick_height-brick_wall, d=intcyl_diameter2, center = false);

                }
        }
    }
}

lego_brick();

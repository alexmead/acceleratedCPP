The lines 97, 99, and 102 would draw errors because they reference a variable of type string
that is not in their scope. Hence, the program won't even compile I believe.

It does in fact compile, however, you get a "segmentation fualt: 11" when it is executed.
I believe this comes because I'm trying to reference a vector that is not in fact there.
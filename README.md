# Dynamic Window Manager

Este es mi propio build de dwm, con algunos parches y configuraciones.

![screenshot.png]

### Parches

- [actualfullscreen:](https://dwm.suckless.org/patches/actualfullscreen/dwm-actualfullscreen-20191112-cb3f58a.diff) Permite activar verdadera pantalla completa en lugar de solo activar el modo monocle y esconder el panel.
- [colorbar:](https://dwm.suckless.org/patches/colorbar/dwm-colorbar-6.2.diff) Diferentes colores en el panel para cada parte del mismo.
- [cyclelayouts:](https://dwm.suckless.org/patches/cyclelayouts/dwm-cyclelayouts-20180524-6.2.diff) Pasa por la lista de layouts con una combinación de botones.
- [fibonacci:](https://dwm.suckless.org/patches/fibonacci/dwm-fibonacci-5.8.2.diff) Dos esquemas nuevos: spiral y dwindle (à la bspwm).
- [fix transparent borders:](https://github.com/szatanjl/dwm/commit/1529909466206016f2101457bbf37c67195714c8) No es un parche "oficial". Arregla los bordes transparentes cuando se usa compton/picom.
- [gridmode:](https://dwm.suckless.org/patches/gridmode/dwm-gridmode-20170909-ceac8c9.diff) Esquema de rejilla para.
- [movestack:](https://dwm.suckless.org/patches/movestack/dwm-movestack-6.1.diff) Permite mover las ventanas en la parte stack, cuando se usa el esquema por defecto.
- [pertag:](https://dwm.suckless.org/patches/pertag/dwm-pertag-20170513-ceac8c9.diff) Por defecto, dwm usa el mismo esquema para todos los tags. Con este parche cada tag tiene un esquema diferente (el esquema inicial es tile).
- [rmaster:](https://dwm.suckless.org/patches/rmaster/dwm-rmaster-6.1.diff) Permite invertir el orden del esquema tile: master a la izquierda y stack a la derecha.
- [uselessgap:](https://dwm.suckless.org/patches/uselessgap/dwm-uselessgap-6.2.diff) Añade separaciones inútiles entre ventanas. Apesar de no ser el único parche, si es el más sencillo de aplicar.
- [xrdb:](https://dwm.suckless.org/patches/xrdb/dwm-xrdb-6.2.diff) Toma colores desde .Xresources.


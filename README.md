* Dynamic Window Manager

Este es mi propio build de DWM, con algunos parches y configuraciones.

*** Parches

**** Funcionales
Aquellos parches que añaden nuevas funciones a DWM, algunas de ellas son funciones sencillas que están presentes en otros TWM.
- [[https://dwm.suckless.org/patches/actualfullscreen/dwm-actualfullscreen-20191112-cb3f58a.diff][actualfullscreen:]] Permite activar verdadera pantalla completa en lugar de solo activar el modo monocle y esconder el panel.
- [[https://dwm.suckless.org/patches/cyclelayouts/dwm-cyclelayouts-20180524-6.2.diff][cyclelayouts:]] Pasa por la lista de layouts con una combinación de botones.
- [[https://dwm.suckless.org/patches/hide_vacant_tags/][hide vacant tags:]] Esconde los tags que no se ocupan al estilo de i3.
- [[https://dwm.suckless.org/patches/movestack/dwm-movestack-6.1.diff][movestack:]] Permite mover las ventanas en la parte stack, cuando se usa el esquema por defecto.
- [[https://dwm.suckless.org/patches/pertag/dwm-pertag-20170513-ceac8c9.diff][pertag:]] Por defecto, dwm usa el mismo esquema para todos los tags. Con este parche cada tag tiene un esquema diferente (el esquema inicial es tile).
- [[https://dwm.suckless.org/patches/switchcol/][switchcol:]] Permite cambiar el foco entre master y stack con un solo /keybinding/. Útil con el layout /deck/.

**** Layouts
Son aquellas /layouts/ nuevas que he agregado a DWM.
- [[https://dwm.suckless.org/patches/centeredmaster/][centeredmaster:]] La ventana /master/ se coloca en el centro mientras las otras aparecen en rejilla alrededor.
- [[https://dwm.suckless.org/patches/deck/][deck:]] La parte /stack/ solo muestra una ventana a la vez. Si se usa con /inplacerotate/ es posible cambiar la ventana en el /stack/ sin mover /master/.
- [[https://dwm.suckless.org/patches/fibonacci/dwm-fibonacci-5.8.2.diff][fibonacci:]] Dos esquemas nuevos: spiral y dwindle (à la bspwm).
- [[https://dwm.suckless.org/patches/gridmode/dwm-gridmode-20170909-ceac8c9.diff][gridmode:]] Esquema de rejilla para.
- [[https://dwm.suckless.org/patches/rmaster/dwm-rmaster-6.1.diff][rmaster:]] Permite invertir el orden del esquema tile: master a la izquierda y stack a la derecha.

**** Estéticos
Parches que unicamente sirven para mejorar el aspecto estético del WM y aportan poco o nada al aspecto funcional.
- [[https://dwm.suckless.org/patches/colorbar/dwm-colorbar-6.2.diff][colorbar:]] Diferentes colores en el panel para cada parte del mismo.
- [[https://github.com/szatanjl/dwm/commit/1529909466206016f2101457bbf37c67195714c8][fix transparent borders:]] No es un parche "oficial". Arregla los bordes transparentes cuando se usa compton/picom.
- [[https://dwm.suckless.org/patches/leftlayout/][leftlayout:]] El símbolo que muestra el /layout/ acutal se mueve a la izquierda. Actualmente no es /clickable/ debido a que entra en conflicto con /hide_vacant_tags/.
- [[https://dwm.suckless.org/patches/status2d/][status2d:]] Permite dibujar cuadros y figuras, además de cambiar el color del texto en los módulos del panel.
- [[https://dwm.suckless.org/patches/uselessgap/dwm-uselessgap-6.2.diff][uselessgap:]] Añade separaciones inútiles entre ventanas. Apesar de no ser el único parche, si es el más sencillo de aplicar.
- [[https://dwm.suckless.org/patches/xrdb/dwm-xrdb-6.2.diff][xrdb:]] Toma colores desde .Xresources.


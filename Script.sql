/* CREATE SCHEMA `db_proveedor` ;

CREATE TABLE `proveedores` (
  `id_Proveedor` int(11) NOT NULL AUTO_INCREMENT,
  `proveedor` varchar(60) DEFAULT NULL,
  `nit` varchar(12) DEFAULT NULL,
  `direccion` varchar(80) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`id_Proveedor`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1

SELECT * FROM db_proveedor.proveedores;
INSERT INTO `db_proveedor`.`proveedores` (`id_Proveedor`, `proveedor`, `nit`, `direccion`, `telefono`) VALUES (' ', ' ', ' ', ' ', ' ');
UPDATE `db_proveedor`.`proveedores` SET `id_Proveedor` = '', `proveedor` = '', `nit` = '', `direccion` = '', `telefono` = '' WHERE (`id_Proveedor` = '1');
DELETE FROM `db_proveedor`.`proveedores` WHERE (`id_Proveedor` = ' ');

*/
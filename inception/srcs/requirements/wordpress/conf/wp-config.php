<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// https://github.com/rhubarbgroup/redis-cache/wiki/Connection-Parameters

// ** Redis settings - You can get this info from your web host ** //

/** Redis hostname */

#define('WP_REDIS_MAXTTL','86400');

define( 'WP_REDIS_HOST', getenv('REDIS_HOST') );

/** Redis port */
define( 'WP_REDIS_PORT', getenv('REDIS_PORT') );

/** The timeout seconds for connection on redis */
define( 'WP_REDIS_TIMEOUT', getenv('REDIS_CON_TIMEOUT') );

/** The timeout seconds for read on redis */
define( 'WP_REDIS_READ_TIMEOUT', getenv('REDIS_READ_TIMEOUT') );

/** The logical database index on redis */
define( 'WP_REDIS_DATABASE', getenv('REDIS_DB_INDEX') );

/** True if do caching */
define( 'WP_CACHE', true );
#define('WP_CACHE_KEY_SALT', 'seongtki.42.fr');

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv('MARIADB_DB') );

/** MySQL database username */
define( 'DB_USER', getenv('MARIADB_USER') );

/** MySQL database password */
define( 'DB_PASSWORD', getenv('MARIADB_PWD') );

/** MySQL hostname */
define( 'DB_HOST', getenv('MARIADB_HOST') );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

/**#@-*/
/* insert keys here */
define('AUTH_KEY',         '{;,Ps+ydx{:&y(oyi8511VH4V79 D6=+w5_~t{Nm,Imi[T!tQ~9s-FmTyWz1|w}_');
define('SECURE_AUTH_KEY',  '-jBuPIk,--.6%oYU$R{=?+1 Fq6^PYb40T?NxFk#:>W|MLpB,e#|<;2`Iaus`{7O');
define('LOGGED_IN_KEY',    '~J9~Q@&k90*Za{TS=V1L%C[u_nvY-vi`fKMV1Al?sf[fm4Ry- m1+O@OkZR6$6NJ');
define('NONCE_KEY',        'jw+U8M5HC/-Rt%EJ9PNc4U;Ph!S_TDt@w7(sal8+,7i--/y%IKs;g@N@Qc/ B+_+');
define('AUTH_SALT',        '*uV0]B:#u*wfDbY%I+N2)V9.Icf3,_ler;)F5P9vB|WJnY#S)rM!NooGH*+?Z2l<');
define('SECURE_AUTH_SALT', 'u|Dj~n(nku|BJLWT+_G6U)NS24WQv;o|esIB%.RJBM2)h=PvGKvKGs!(a0cUaj{f');
define('LOGGED_IN_SALT',   'PBf]PPeKN876L``N ]w/Wc}>wJAdcWb+]u1mapeh O;~1<;+][#7_kD(-@OdA<xA');
define('NONCE_SALT',       '+3f17i0%S1KA&r$y;No|yDN;I|t5Ko-A:|Oq&(;<-;+UZ%8gSA<+IS^(g>T38=pn');

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';


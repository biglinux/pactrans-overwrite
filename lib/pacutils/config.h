
#include <alpm.h>

#ifndef PACUTILS_CONFIG_H
#define PACUTILS_CONFIG_H

typedef enum pu_config_option_t {
  PU_CONFIG_OPTION_ROOTDIR,
  PU_CONFIG_OPTION_DBPATH,
  PU_CONFIG_OPTION_GPGDIR,
  PU_CONFIG_OPTION_LOGFILE,
  PU_CONFIG_OPTION_ARCHITECTURE,
  PU_CONFIG_OPTION_XFERCOMMAND,

  PU_CONFIG_OPTION_CLEANMETHOD,
  PU_CONFIG_OPTION_COLOR,
  PU_CONFIG_OPTION_USESYSLOG,
  PU_CONFIG_OPTION_USEDELTA,
  PU_CONFIG_OPTION_TOTALDOWNLOAD,
  PU_CONFIG_OPTION_CHECKSPACE,
  PU_CONFIG_OPTION_VERBOSEPKGLISTS,
  PU_CONFIG_OPTION_ILOVECANDY,

  PU_CONFIG_OPTION_SIGLEVEL,
  PU_CONFIG_OPTION_LOCAL_SIGLEVEL,
  PU_CONFIG_OPTION_REMOTE_SIGLEVEL,

  PU_CONFIG_OPTION_HOLDPKGS,
  PU_CONFIG_OPTION_IGNOREPKGS,
  PU_CONFIG_OPTION_IGNOREGROUPS,
  PU_CONFIG_OPTION_NOUPGRADE,
  PU_CONFIG_OPTION_NOEXTRACT,
  PU_CONFIG_OPTION_REPOS,
  PU_CONFIG_OPTION_CACHEDIRS,

  PU_CONFIG_OPTION_SERVER,

  PU_CONFIG_OPTION_USAGE,

  PU_CONFIG_OPTION_INCLUDE
} pu_config_option_t;

/* config */
typedef enum pu_config_cleanmethod_t {
  PU_CONFIG_CLEANMETHOD_KEEP_INSTALLED = (1 << 0),
  PU_CONFIG_CLEANMETHOD_KEEP_CURRENT   = (1 << 1),
} pu_config_cleanmethod_t;

typedef struct pu_config_t {
  char *rootdir;
  char *dbpath;
  char *gpgdir;
  char *logfile;
  char *architecture;
  char *xfercommand;

  unsigned short usesyslog;
  unsigned short totaldownload;
  unsigned short checkspace;
  unsigned short verbosepkglists;
  unsigned short color;
  unsigned short ilovecandy;

  float usedelta;

  alpm_siglevel_t siglevel;
  alpm_siglevel_t localfilesiglevel;
  alpm_siglevel_t remotefilesiglevel;

  alpm_siglevel_t siglevel_mask;
  alpm_siglevel_t localfilesiglevel_mask;
  alpm_siglevel_t remotefilesiglevel_mask;

  alpm_list_t *holdpkgs;
  alpm_list_t *ignorepkgs;
  alpm_list_t *ignoregroups;
  alpm_list_t *noupgrade;
  alpm_list_t *noextract;
  alpm_list_t *cachedirs;

  pu_config_cleanmethod_t cleanmethod;

  alpm_list_t *repos;
} pu_config_t;

/* sync repos */
typedef struct pu_repo_t {
	char *name;
	alpm_list_t *servers;
	alpm_db_usage_t usage;
	alpm_siglevel_t siglevel;
	alpm_siglevel_t siglevel_mask;
} pu_repo_t;

struct pu_repo_t *pu_repo_new(void);
void pu_repo_free(pu_repo_t *repo);
alpm_db_t *pu_register_syncdb(alpm_handle_t *handle, struct pu_repo_t *repo);
alpm_list_t *pu_register_syncdbs(alpm_handle_t *handle, alpm_list_t *repos);

struct pu_config_t *pu_config_new(void);
struct pu_config_t *pu_config_new_from_file(const char *filename);
void pu_config_free(pu_config_t *config);

alpm_handle_t *pu_initialize_handle_from_config(struct pu_config_t *config);

#endif /* PACUTILS_CONFIG_H */

/* vim: set ts=2 sw=2 et: */

/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file  ap_config_layout.h
 * @brief Apache Config Layout
 */

#ifndef AP_CONFIG_LAYOUT_H
#define AP_CONFIG_LAYOUT_H

/* Configured Apache directory layout */
#define DEFAULT_PREFIX "/var/httpd/"
#define DEFAULT_EXP_EXEC_PREFIX "/var/httpd/"
#define DEFAULT_REL_EXEC_PREFIX ""
#define DEFAULT_EXP_BINDIR "/var/httpd//bin"
#define DEFAULT_REL_BINDIR "bin"
#define DEFAULT_EXP_SBINDIR "/var/httpd//bin"
#define DEFAULT_REL_SBINDIR "bin"
#define DEFAULT_EXP_LIBEXECDIR "/var/httpd//modules"
#define DEFAULT_REL_LIBEXECDIR "modules"
#define DEFAULT_EXP_MANDIR "/var/httpd//man"
#define DEFAULT_REL_MANDIR "man"
#define DEFAULT_EXP_SYSCONFDIR "/var/httpd//conf"
#define DEFAULT_REL_SYSCONFDIR "conf"
#define DEFAULT_EXP_DATADIR "/var/httpd/"
#define DEFAULT_REL_DATADIR ""
#define DEFAULT_EXP_INSTALLBUILDDIR "/var/httpd//build"
#define DEFAULT_REL_INSTALLBUILDDIR "build"
#define DEFAULT_EXP_ERRORDIR "/var/httpd//error"
#define DEFAULT_REL_ERRORDIR "error"
#define DEFAULT_EXP_ICONSDIR "/var/httpd//icons"
#define DEFAULT_REL_ICONSDIR "icons"
#define DEFAULT_EXP_HTDOCSDIR "/var/httpd//htdocs"
#define DEFAULT_REL_HTDOCSDIR "htdocs"
#define DEFAULT_EXP_MANUALDIR "/var/httpd//manual"
#define DEFAULT_REL_MANUALDIR "manual"
#define DEFAULT_EXP_CGIDIR "/var/httpd//cgi-bin"
#define DEFAULT_REL_CGIDIR "cgi-bin"
#define DEFAULT_EXP_INCLUDEDIR "/var/httpd//include"
#define DEFAULT_REL_INCLUDEDIR "include"
#define DEFAULT_EXP_LOCALSTATEDIR "/var/httpd/"
#define DEFAULT_REL_LOCALSTATEDIR ""
#define DEFAULT_EXP_RUNTIMEDIR "/var/httpd//logs"
#define DEFAULT_REL_RUNTIMEDIR "logs"
#define DEFAULT_EXP_LOGFILEDIR "/var/httpd//logs"
#define DEFAULT_REL_LOGFILEDIR "logs"
#define DEFAULT_EXP_PROXYCACHEDIR "/var/httpd//proxy"
#define DEFAULT_REL_PROXYCACHEDIR "proxy"

#endif /* AP_CONFIG_LAYOUT_H */

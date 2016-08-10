#!/bin/bash
# Usage: $0 [version]

display_usage() {
    echo -e "\nUsage:\n$0 [-h] [-l] [version] \n" 
    echo -e " where:"
    echo -e "  -h  show this help text"
    echo -e "  [version] is the two number identifying version 7"
}

# if less than two arguments supplied, display usage 
if [  $# -le 0 ] 
then 
    display_usage
    exit 1
fi 

# check whether user had supplied -h or --help . If yes display usage 
if [[ ( $# == "--help") ||  $# == "-h" ]] 
then 
    display_usage
    exit 0
fi 

VERSION=$1
DRUPAL=`echo 'drupal-7.'$VERSION`

red='\033[0;31m'
green='\033[0;32m'
NC='\033[0m' # No Color
url=`echo 'http://ftp.drupal.org/files/projects/'$DRUPAL'.tar.gz'`

if [ -d $DRUPAL ]
then
  echo "${red}You already have $DRUPAL${NC}"
  exit 0
fi

# Fetch the header
if [ `curl -o /dev/null --silent --head --write-out '%{http_code}\n' $url` == '200' ]
then
    echo "${green}Downloading and unpacking $DRUPAL${NC}"
    curl $url | tar -xf- -C .
else
    echo "${red}Are you sure you want to fetch $DRUPAL ? It seems like it does not exist here: $url${NC}"
fi

if [ ! -d $DRUPAL ]
then
  echo "${red}Something went wrong! try to download manually ${NC}"
  exit 0
fi

echo "${green}Linking to the upgraded version${NC}"
unlink src
ln -sf $DRUPAL src

echo "${green}Linking to our sites${NC}"
cd $DRUPAL
rm -rf sites
ln -s ../sites .

echo "${green}Upgrading and cleaning caches${NC}"
drush @unescorg.local updb

echo "${green}Copy useful files to $DRUPAL${NC}"
echo "cp local_htaccess $DRUPAL/.htaccess"
echo "cp robots.txt $DRUPAL/robots.txt"
echo "cp favicon.ico $DRUPAL/favicon.ico"

-- SUMMARY --

The Organic Groups Statistics module (og_statistics) provides a streamlined way to track and present useful information about existing Organic Groups, including via Views fields and faceted search.

For a full description of the module, visit the project page:
  http://drupal.org/project/og_statistics

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/og_statistics

-- REQUIREMENTS --

Organic Groups (og) & Organic Groups Views (og_views)

-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.

Upon installation, the module begins to track several different statistics related to all organic groups, and nodes are tracked after they are added.

The index has to be rebuilt to include already-existing nodes at the time of installation (see Configuration below).

A new database table schema (og_statistics) is created to track organic group statistics, and activity in all nodes in a group. Here are the fields which can be accessed via Views:

* members_count: how many members a group node has.
* posts_count: how many posts (nodes) a group node has.
* comments_count: how many comments a group node has.
* last_node_timestamp: the last time a node in the group was created.
* last_comment_timestamp: the last time a comment on the group node was created.
* last_member_timestamp: the last time a user joins the group.
* last_comment_uid: the last User UID to post a comment on the group.
* last_comment_nid: the Node NID of the last node commented upon in the group.
* last_comment_cid: the last comment's comment id (CID) in the group.
* last_node_nid: the last Node NID posted to the group.
* last_node_uid: the last User UID to post to the group.
* last_member_uid: the last User UID to join a group.

To un-install, use the normal uninstallation tab within /admin/build/modules and the table will be deleted.

-- CONFIGURATION & VIEWS SETUP --

* To setup the module, enable it and go to "Og Statistics settings" at /admin/settings/og_statistics

Users require the "administer organic groups" to view or change settings.

Option:
* "Include unapproved members in membership count" - if unchecked, users must be approved to be included in the tally.

* To add fields in Views UI for displaying organic group statistics:
- First, setup a Relationship in a View (the View should be linked to the Node table):
-- ie add Relationship: "Organic groups: Group node (post) - Bring in information about the group node based on a post's groups." The default settings will work.

Then add fields with desired organic group statistical info via the Fields interface, including:

* OG Statistics: Group Statistic: Comments Count
* OG Statistics: Group Statistic: Last Comment-time
* OG Statistics: Group Statistic: Last inserted/updated Node-time
* OG Statistics: Group Statistic: Members Count
* OG Statistics: Group Statistic: Posts Count
* OG Statistics: Group Statistic: last Member subscription

The fields should reflect the values, and tailor the prefix/suffix strings for the fields to style them individually.

* Faceted search: adds the option "Sort by number of group nodes" to the faceted search form: "If only searching group content types enables sorting by the most recent node added to the group, rather than comment added to the group node itself."

-- TESTING --

og_statistics has automated testing features to verify its functionality. 

Test functions include TestOgStatisticsWritePureRecord, TestOgStatisticsNodeapi, TestOgStatisticsComment, TestOgStatisticsOg, and TestOgStatisticsDelete . 

The test class is OgStatisticsTestCase . 

For more information on testing see http://drupal.org/simpletest

-- TROUBLESHOOTING --

* Not all the nodes are counted:

  - Has the index been rebuilt since those nodes were added? Rebuild the index and see if that works.
  
* Rebuild fails with batch / access denied message:
  - The Drupal 6 batch routine may not be able to process everything. See http://drupal.org/node/1047986 for a workaround, using the Drupal Tweaks module ( http://drupal.org/project/drupal_tweaks ) to boost the Max_allowed_packet size value on the server.

-- CONTACT --

Current maintainer:
* Daniel Wehner (dereine) - http://drupal.org/user/99340

* This readme file written by Dan Feidt (HongPong) - http://drupal.org/user/60005 ) at Drupalcon 2011 Docs Code Sprint!
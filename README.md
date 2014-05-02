URLS handled by this solution pack.
-----------------------------------
http://<serverurl>/vocabulary
http://<serverurl>/vocabulary/A
    where "A" is the initial of the term (can be "A" to "Z", uppercase only).
http://<serverurl>/vocabulary/other
    for all terms not having an alphabetic initial


http://<serverurl>/geographicterms
http://<serverurl>/geographicterms/A
    where "A" is the initial of the term (can be "A" to "Z", uppercase only).
http://<serverurl>/geographicterms/other
    for all terms not having an alphabetic initial


solr configuration
------------------

In the /usr/local/fedora/gsearch_solr/solr/conf/schema.xml file:

    <fieldType name="fbastring" class="solr.StrField" sortMissingLast="true" omitNorms="true">
        <filter class="solr.LengthFilterFactory" min="1" />
    </fieldType>
    <!--case insensitive type for autocompletion over vocab terms-->
    <fieldType name="fbastring_ci" class="solr.TextField" sortMissingLast="true" omitNorms="true">
         <analyzer type="query">
           <tokenizer class="solr.KeywordTokenizerFactory"/>
           <filter class="solr.LowerCaseFilterFactory"/>
         </analyzer>
    </fieldType>

    <!-- For the initials of the authorities and variants -->
    <fieldType name="fba_text_initial" class="solr.TextField" positionIncrementGap="100">
      <analyzer type="index">
        <tokenizer class="solr.WhitespaceTokenizerFactory"/>
        <filter class="solr.LowerCaseFilterFactory"/>
        <filter class="solr.RemoveDuplicatesTokenFilterFactory"/>
      </analyzer>
      <analyzer type="query">
        <tokenizer class="solr.WhitespaceTokenizerFactory"/>
        <filter class="solr.LowerCaseFilterFactory"/>
        <filter class="solr.RemoveDuplicatesTokenFilterFactory"/>
      </analyzer>
    </fieldType>


   <field name="mads.identifier" type="text" indexed="true" stored="true"/>
   <field name="mads.authority" type="fbastring" indexed="true" stored="true"/>
   <field name="mads.variant" type="fbastring" indexed="true" stored="true"/>
   <field name="mads.authorityCI" type="fbastring_ci" indexed="true" stored="true"/>
   <field name="mads.broader" type="fbastring" indexed="true" stored="true" multiValued="true"/>
   <field name="mads.narrower" type="fbastring" indexed="true" stored="true" multiValued="true"/>
   <field name="mads.related" type="fbastring" indexed="true" stored="true" multiValued="true"/>
   <field name="mads.usefor" type="fbastring" indexed="true" stored="true" multiValued="true"/>
   <field name="mads.useinstead" type="fbastring" indexed="true" stored="true" multiValued="true"/>
   <field name="mads.hasgeographicfeature" type="fbastring" indexed="true" stored="true" multiValued="true"/>
   <field name="mads.isgeographicfeatureof" type="fbastring" indexed="true" stored="true" multiValued="true"/>
   <field name="mads.initials" type="fba_text_initial" indexed="true" stored="true" multiValued="true"/>

"initials", "authority", "variant" are the only fields required for this solution
pack, but the others are fields used for the vocabulary and autocomplete solution packs.

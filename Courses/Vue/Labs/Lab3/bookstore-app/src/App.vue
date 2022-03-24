<template>
  <NavBar />
  <router-view />
</template>

<script>
import NavBar from "./components/NavBarComponent.vue";

export default {
  name: "App",
  components: {
    NavBar,
  },
};
</script>


<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
}
</style>
